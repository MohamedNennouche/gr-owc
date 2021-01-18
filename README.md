# gr-owc
GNURadio out-ot-tree (OOT) module for optical wireless communications. Contact person regarding for module is Dr. Michael Rahaim <Michael.Rahaim@umb.edu> from The Ubiquitous Communications and Networking (UCAN) Lab, University of Massachusetts, Boston.

This installation guide assumes that GNU Radio has been installed using PyBOMBS.

To download and install, follow the steps below:

1-) First of all download this repository by cloning with git clone <url>

2-) Source the setup of the desired GNU Radio prefix in the terminal

3-) cd to the gr-testmodule directory

4-) Create a build directory with 'mkdir build' and move into the directory with 'cd build/'

5-) Run cmake (the path to the sourced GNU Radio installation would be found automatically): 'cmake ../'

6-) Run 'make'

7-) Test the build with 'make test' (shouldn't be any failures)

8-) Install with 'make install'

9-) Configure your linker/debugger with 'sudo ldconfig'

10-) Open gnuradio-companion and you should find a module for gr-owc.
