/* -*- c++ -*- */
/* gr-owc OOT module for optical wireless communications. 
 *
 * Copyright 2021 Arsalan Ahmed from The Ubiquitous Communications and Networking (UCAN) Lab, University of Massachusetts, Boston.
 *
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 *
 */

#ifndef INCLUDED_OWC_OWC_CHANNEL_ABSOLUTE_TWO_H
#define INCLUDED_OWC_OWC_CHANNEL_ABSOLUTE_TWO_H

#include <owc/api.h>
#include <gnuradio/sync_block.h>

namespace gr {
  namespace owc {

    /*!
     * \brief <+description of block+>
     * \ingroup owc
     *
     */
    class OWC_API OWC_Channel_absolute_two : virtual public gr::sync_block
    {
     public:
      typedef boost::shared_ptr<OWC_Channel_absolute_two> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of owc::OWC_Channel_absolute_two.
       *
       * To avoid accidental use of raw pointers, owc::OWC_Channel_absolute_two's
       * constructor is in a private implementation
       * class. owc::OWC_Channel_absolute_two::make is the public interface for
       * creating new instances.
       */
      static sptr make(int num_inputs, int num_outputs, const std::vector<float>& tx_coordinates_array, const std::vector<float>& tx_orientation_array, const std::vector<float>& rx_coordinates_array, const std::vector<float>& rx_orientation_array, const std::vector<float>& tx_lambertian_order_array, const std::vector<float>& rx_photosensor_area_array, const std::vector<float>& optical_filter_transmittance_array, const std::vector<float>& refractive_index_array, const std::vector<float>& concentrator_FOV_array, const std::vector<float>& E2O_conversion_factor_array, const std::vector<float>& O2E_conversion_factor_array, int sample_rate, const std::vector<int>& blockage_array, const std::vector<float>& noise_power_array);
      virtual void set_tx_coordinates_array(std::vector<float> tx_coordinates_array) = 0;
      virtual std::vector<float> tx_coordinates_array() = 0;   
      
      virtual void set_tx_orientation_array(std::vector<float> tx_orientation_array) = 0;
      virtual std::vector<float> tx_orientation_array() = 0; 
      
      virtual void set_rx_coordinates_array(std::vector<float> rx_coordinates_array) = 0;
      virtual std::vector<float> rx_coordinates_array() = 0;    
      
      virtual void set_rx_orientation_array(std::vector<float> rx_orientation_array) = 0;
      virtual std::vector<float> rx_orientation_array() = 0; 
      
      virtual void set_tx_lambertian_order_array(std::vector<float> lambertian_order_array) = 0;
      virtual std::vector<float> tx_lambertian_order_array() = 0; 

      virtual void set_blockage_array(std::vector<int> blockage_array) = 0;
      virtual std::vector<int> blockage_array() = 0;
      
      virtual void set_noise_power_array(std::vector<float> noise_power_array) = 0;
      virtual std::vector<float> noise_power_array() = 0;
    };

  } // namespace owc
} // namespace gr

#endif /* INCLUDED_OWC_OWC_CHANNEL_ABSOLUTE_TWO_H */

