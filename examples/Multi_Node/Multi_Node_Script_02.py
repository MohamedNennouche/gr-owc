from xmlrpc.client import ServerProxy
import zmq
import numpy as np
import time

########### 0 for Singal & 1 for Tone
Signal_Selection = 0
############# Disable Constant Value
DISABLED = 2
############
Filter_ON = 1
Filter_Off = 0
Filter_Values = [1.5e9, 2.0e9]
######## Time Delay in Seconds
time_delay = 1
time_delay_2 = 3
###########

tx_1_settings = [DISABLED,Signal_Selection,DISABLED,Signal_Selection]
tx_2_settings = [DISABLED,Signal_Selection,Signal_Selection,DISABLED]
filter_settting = [Filter_ON,Filter_Off]


def power_measurement(socket):
    latest_msg = None
    try:
        while socket.poll(0):  # As long as there are messages in the buffer
            latest_msg = socket.recv(flags=zmq.NOBLOCK)  # Overwrite latest_msg with the new message
    except zmq.Again:
        pass  # Buffer is now drained, and latest_msg contains the last message
    
    if latest_msg is not None:  # If we got at least one message
        data = np.frombuffer(latest_msg, dtype=np.float32, count=-1)
        avg_power = np.average(data)
        return avg_power
    else:
        return None


# Initialize server proxies
STA2_control = ServerProxy('http://10.1.1.2:8080')
STA3_control = ServerProxy('http://10.1.1.3:8080')

# Set up ZMQ for Signal 1
context = zmq.Context()
socket1 = context.socket(zmq.SUB)
socket1.connect("tcp://10.1.1.3:55555")
socket1.setsockopt(zmq.SUBSCRIBE, b'')

# Set up ZMQ for Signal 2
context2 = zmq.Context()
socket2 = context2.socket(zmq.SUB)
socket2.connect("tcp://10.1.1.3:55556")
socket2.setsockopt(zmq.SUBSCRIBE, b'')


###########################################################
# Set the path for Signal 1 and Signal 2 before measurements
# Pair tx_1_settings and tx_2_settings in tuples and loop through them
paired_settings = zip(tx_1_settings, tx_2_settings)

# Inside the existing for loop for tx_1 and tx_2 settings
for tx1, tx2 in paired_settings:
    print(f"[Current Settings {tx1} {tx2}]")
    STA2_control.set_path_select_1(tx1)
    STA2_control.set_path_select_2(tx2)
    time.sleep(time_delay_2)

    # Inner loop for filter settings
    for filt in filter_settting:
        
        # When filter should be OFF, both are OFF
        if filt == Filter_Off:
            print("[Both Filters OFF]")
            STA3_control.set_select_filter_1(Filter_Off)
            STA3_control.set_select_filter_2(Filter_Off)
            
            # Take power measurement
            avg_power1 = power_measurement(socket1)
            avg_power2 = power_measurement(socket2)
            print(f" Power 1: {avg_power1 if avg_power1 is not None else 'No message'}, Power 2: {avg_power2 if avg_power2 is not None else 'No message'}")
        
        # When filter should be ON, alternate turning Filter_1 and Filter_2 ON
        else:
            # Filter_1 ON, Filter_2 OFF
            print("[Filter 1 ON, Filter 2 OFF]")
            STA3_control.set_select_filter_1(Filter_ON)
            STA3_control.set_select_filter_2(Filter_Off)
            for val in Filter_Values:
                print(f"[Filter 1 Value {val}]")
                STA3_control.set_filter_value_1(val)
                
                # Take power measurement
                avg_power1 = power_measurement(socket1)
                avg_power2 = power_measurement(socket2)
                print(f" Power 1: {avg_power1 if avg_power1 is not None else 'No message'}, Power 2: {avg_power2 if avg_power2 is not None else 'No message'}")
            
            # Filter_1 OFF, Filter_2 ON
            print("[Filter 1 OFF, Filter 2 ON]")
            STA3_control.set_select_filter_1(Filter_Off)
            STA3_control.set_select_filter_2(Filter_ON)
            for val in Filter_Values:
                print(f"[Filter 2 Value {val}]")
                STA3_control.set_filter_value_2(val)
                
                # Take power measurement
                avg_power1 = power_measurement(socket1)
                avg_power2 = power_measurement(socket2)
                print(f" Power 1: {avg_power1 if avg_power1 is not None else 'No message'}, Power 2: {avg_power2 if avg_power2 is not None else 'No message'}")