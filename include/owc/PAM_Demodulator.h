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

#ifndef INCLUDED_OWC_PAM_DEMODULATOR_H
#define INCLUDED_OWC_PAM_DEMODULATOR_H

#include <owc/api.h>
#include <gnuradio/sync_decimator.h>

namespace gr {
  namespace owc {

    /*!
     * \brief <+description of block+>
     * \ingroup owc
     *
     */
    class OWC_API PAM_Demodulator : virtual public gr::sync_decimator
    {
     public:
      typedef boost::shared_ptr<PAM_Demodulator> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of owc::PAM_Demodulator.
       *
       * To avoid accidental use of raw pointers, owc::PAM_Demodulator's
       * constructor is in a private implementation
       * class. owc::PAM_Demodulator::make is the public interface for
       * creating new instances.
       */
      static sptr make(int modulation_order, float max_magnitude, float min_magnitude, int samples_per_symbol);
      
      virtual void set_max_magnitude(float max_magnitude) = 0;
      virtual float max_magnitude() = 0;
      
      virtual void set_min_magnitude(float min_magnitude) = 0;
      virtual float min_magnitude() = 0;
    };

  } // namespace owc
} // namespace gr

#endif /* INCLUDED_OWC_PAM_DEMODULATOR_H */

