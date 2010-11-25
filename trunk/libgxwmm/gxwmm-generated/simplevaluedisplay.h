// -*- c++ -*-
// Generated by gtkmmproc -- DO NOT MODIFY!
#ifndef _GXWMM_SIMPLEVALUEDISPLAY_H
#define _GXWMM_SIMPLEVALUEDISPLAY_H


#include <glibmm.h>

/*
 * Copyright (C) 2009, 2010 Hermann Meyer, James Warden, Andreas Degert
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#include <gxwmm/regler.h>
#include <gtkmm/adjustment.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GxSimpleValueDisplay GxSimpleValueDisplay;
typedef struct _GxSimpleValueDisplayClass GxSimpleValueDisplayClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gxw
{ class SimpleValueDisplay_Class; } // namespace Gxw
namespace Gxw {


class SimpleValueDisplay: public Gxw::Regler {
	public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef SimpleValueDisplay CppObjectType;
  typedef SimpleValueDisplay_Class CppClassType;
  typedef GxSimpleValueDisplay BaseObjectType;
  typedef GxSimpleValueDisplayClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  virtual ~SimpleValueDisplay();

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend class SimpleValueDisplay_Class;
  static CppClassType simplevaluedisplay_class_;

  // noncopyable
  SimpleValueDisplay(const SimpleValueDisplay&);
  SimpleValueDisplay& operator=(const SimpleValueDisplay&);

protected:
  explicit SimpleValueDisplay(const Glib::ConstructParams& construct_params);
  explicit SimpleValueDisplay(GxSimpleValueDisplay* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static GType get_type()      G_GNUC_CONST;


  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GtkObject.
  GxSimpleValueDisplay*       gobj()       { return reinterpret_cast<GxSimpleValueDisplay*>(gobject_); }

  ///Provides access to the underlying C GtkObject.
  const GxSimpleValueDisplay* gobj() const { return reinterpret_cast<GxSimpleValueDisplay*>(gobject_); }


public:
  //C++ methods used to invoke GTK+ virtual functions:
#ifdef GLIBMM_VFUNCS_ENABLED
#endif //GLIBMM_VFUNCS_ENABLED

protected:
  //GTK+ Virtual Functions (override these to change behaviour):
#ifdef GLIBMM_VFUNCS_ENABLED
#endif //GLIBMM_VFUNCS_ENABLED

  //Default Signal Handlers::
#ifdef GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
#endif //GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED


private:

	public:
	SimpleValueDisplay();
	explicit SimpleValueDisplay(Gtk::Adjustment& adjustment);


};

} // namespace Gxw


namespace Glib
{
  /** A Glib::wrap() method for this object.
   * 
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gxw::SimpleValueDisplay
   */
  Gxw::SimpleValueDisplay* wrap(GxSimpleValueDisplay* object, bool take_copy = false);
} //namespace Glib


#endif /* _GXWMM_SIMPLEVALUEDISPLAY_H */

