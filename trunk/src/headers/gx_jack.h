/*
 * Copyright (C) 2009, 2010 Hermann Meyer, James Warden, Andreas Degert
 * Copyright (C) 2011 Pete Shorthose
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
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 * --------------------------------------------------------------------------
 */

/* ------- This is the JACK namespace ------- */

#pragma once

#ifndef SRC_HEADERS_GX_JACK_H_
#define SRC_HEADERS_GX_JACK_H_

/* On Intel set FZ (Flush to Zero) and DAZ (Denormals Are Zero)
   flags to avoid costly denormals */
#ifdef __SSE__
#include <xmmintrin.h>
#ifdef __SSE2__
#define AVOIDDENORMALS _mm_setcsr(_mm_getcsr() | 0x8040)
#else
#define AVOIDDENORMALS _mm_setcsr(_mm_getcsr() | 0x8000)
#endif
#else
#define AVOIDDENORMALS
#endif

#include <jack/jack.h>          // NOLINT
#include <jack/midiport.h>
#include <semaphore.h>

#ifdef HAVE_JACK_SESSION
#include <jack/session.h>
#endif

#include <string>

namespace gx_jack {

class GxJack {
 private:
    bool                gx_start_jack_dialog();
    bool                gx_start_jack(void* arg);
    gx_engine::GxEngine& engine;
    bool                jack_is_down;
    bool                jack_is_exit;
    static int          gx_jack_srate_callback(jack_nframes_t, void* arg);
    static int          gx_jack_xrun_callback(void* arg);
    static int          gx_jack_buffersize_callback(jack_nframes_t, void* arg);
    static int          gx_jack_process(jack_nframes_t, void* arg);
    static int          gx_jack_insert_process(jack_nframes_t, void* arg);

    static void         gx_jack_shutdown_callback(void* arg);
    static void         gx_jack_portreg_callback(jack_port_id_t, int, void* arg);
    static void         gx_jack_portconn_callback(jack_port_id_t a, jack_port_id_t b, int connect, void* arg);
#ifdef HAVE_JACK_SESSION
    static void         gx_jack_session_callback(jack_session_event_t *event, void *arg);
#endif
    void                gx_jack_activate();
 public:
    bool                is_jack_down() { return jack_is_down; }
    void                set_jack_down(bool);
    bool                is_jack_exit() { return jack_is_exit; }
    void                set_jack_exit(bool);
    static const int    nIPorts = 2; // for both jack clients
    static const int    nOPorts = 4; // 2 * stereo output (1 unused)
    jack_nframes_t      jack_sr;   // jack sample rate
    jack_nframes_t      jack_bs;   // jack buffer size
    jack_nframes_t      time_is;

    jack_client_t*      client;
    jack_client_t*      client_insert;
    jack_port_t*        output_ports[nOPorts];
    jack_port_t*        input_ports[nIPorts];
    jack_port_t*        midi_input_port;
    jack_port_t*        midi_output_ports;

    void*               midi_input_port_buf;
    void*               midi_port_buf;

    float               jcpu_load; // jack cpu_load
    float               xdel;      // last xrun delay

    int                 is_rt;
public:
    GxJack(gx_engine::GxEngine& engine_);
    bool                gx_jack_init(const string *optvar );
    
    void                gx_set_jack_buffer_size(GtkCheckMenuItem*, void* arg);
    void                gx_jack_connection(GtkCheckMenuItem*);

    int                 gx_jack_midi_process(jack_nframes_t, float *input);
    int                 gx_jack_midi_input_process(jack_nframes_t);

    void                gx_jack_init_port_connection(const string*);
    void                gx_jack_callbacks();
    void                gx_jack_cleanup();
    string              client_instance;
    string              client_name;
    string              client_insert_name;

    /* lists of jack port types for menu items */
    enum {
        kAudioInput    = 0,
        kAudioOutput1  = 1,
        kAudioOutput2  = 2,
        kMidiInput     = 3,
        kMidiOutput    = 4,
        kAudioInsertIn = 5,
        kAudioInsertOut= 6
    };

    enum GxJackLatencyChange {
        kChangeLatency = 1,
        kKeepLatency   = 2
    };

    GxJackLatencyChange change_latency;
};

class JackBuffer {
 public:
    float               *input;
    float               *input1;
    float               *output0;
    float               *output2;
    float               *output3;
};
extern JackBuffer *_jackbuffer_ptr;

} /* end of jack namespace */

gx_jack::GxJack& get_jack(gx_engine::GxEngine* engine_ = 0);

#endif  // SRC_HEADERS_GX_JACK_H_
