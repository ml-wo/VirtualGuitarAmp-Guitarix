// generated from file '../src/plugins/bmp.dsp' by dsp2cc:
// Code generated with Faust 0.9.65 (http://faust.grame.fr)

#include "gx_faust_support.h"
#include "gx_plugin.h"

namespace pluginlib {
namespace bmp {

class Dsp: public PluginDef {
private:
	gx_resample::FixedRateResampler smp;
	int samplingFreq;
	int fSamplingFreq;
	FAUSTFLOAT 	fslider0;
	double 	fRec0[2];
	double 	fConst0;
	double 	fConst1;
	double 	fConst2;
	double 	fConst3;
	double 	fConst4;
	double 	fConst5;
	double 	fConst6;
	double 	fConst7;
	double 	fConst8;
	FAUSTFLOAT 	fslider1;
	double 	fRec2[2];
	double 	fConst9;
	double 	fConst10;
	double 	fConst11;
	double 	fConst12;
	double 	fConst13;
	double 	fConst14;
	double 	fConst15;
	double 	fConst16;
	double 	fConst17;
	double 	fConst18;
	double 	fConst19;
	double 	fConst20;
	double 	fConst21;
	double 	fConst22;
	double 	fConst23;
	double 	fConst24;
	double 	fConst25;
	double 	fConst26;
	double 	fConst27;
	FAUSTFLOAT 	fslider2;
	double 	fRec7[2];
	double 	fConst28;
	double 	fConst29;
	double 	fConst30;
	double 	fConst31;
	double 	fConst32;
	double 	fConst33;
	double 	fConst34;
	double 	fConst35;
	double 	fConst36;
	double 	fConst37;
	double 	fConst38;
	double 	fConst39;
	double 	fConst40;
	double 	fConst41;
	double 	fRec9[3];
	double 	fConst42;
	double 	fConst43;
	double 	fRec8[3];
	double 	fConst44;
	double 	fConst45;
	double 	fRec6[5];
	double 	fConst46;
	double 	fConst47;
	double 	fConst48;
	double 	fConst49;
	double 	fConst50;
	double 	fRec5[3];
	double 	fConst51;
	double 	fConst52;
	double 	fConst53;
	double 	fConst54;
	double 	fRec4[5];
	double 	fRec3[3];
	double 	fConst55;
	double 	fConst56;
	double 	fRec1[3];
	double 	fConst57;
	void clear_state_f();
	int load_ui_f(const UiBuilder& b, int form);
	static const char *glade_def;
	void init(unsigned int samplingFreq);
	void compute(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0);
	int register_par(const ParamReg& reg);

	static void clear_state_f_static(PluginDef*);
	static int load_ui_f_static(const UiBuilder& b, int form);
	static void init_static(unsigned int samplingFreq, PluginDef*);
	static void compute_static(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0, PluginDef*);
	static int register_params_static(const ParamReg& reg);
	static void del_instance(PluginDef *p);
public:
	Dsp();
	~Dsp();
};



Dsp::Dsp()
	: PluginDef() {
	version = PLUGINDEF_VERSION;
	flags = 0;
	id = "bmp";
	name = N_("BigMuffPi");
	groups = 0;
	description = N_("BigMuffPi"); // description (tooltip)
	category = N_("Fuzz");       // category
	shortname = N_("BMP");     // shortname
	mono_audio = compute_static;
	stereo_audio = 0;
	set_samplerate = init_static;
	activate_plugin = 0;
	register_params = register_params_static;
	load_ui = load_ui_f_static;
	clear_state = clear_state_f_static;
	delete_instance = del_instance;
}

Dsp::~Dsp() {
}

inline void Dsp::clear_state_f()
{
	for (int i=0; i<2; i++) fRec0[i] = 0;
	for (int i=0; i<2; i++) fRec2[i] = 0;
	for (int i=0; i<2; i++) fRec7[i] = 0;
	for (int i=0; i<3; i++) fRec9[i] = 0;
	for (int i=0; i<3; i++) fRec8[i] = 0;
	for (int i=0; i<5; i++) fRec6[i] = 0;
	for (int i=0; i<3; i++) fRec5[i] = 0;
	for (int i=0; i<5; i++) fRec4[i] = 0;
	for (int i=0; i<3; i++) fRec3[i] = 0;
	for (int i=0; i<3; i++) fRec1[i] = 0;
}

void Dsp::clear_state_f_static(PluginDef *p)
{
	static_cast<Dsp*>(p)->clear_state_f();
}

inline void Dsp::init(unsigned int RsamplingFreq)
{
	samplingFreq = 96000;
	smp.setup(RsamplingFreq, samplingFreq);
	fSamplingFreq = samplingFreq;
	fConst0 = double(min(192000, max(1, fSamplingFreq)));
	fConst1 = (4.33884681055068e-10 * fConst0);
	fConst2 = (2.65226702159437e-08 + (fConst0 * (fConst1 - 6.86809013445937e-09)));
	fConst3 = faustpower<2>(fConst0);
	fConst4 = (5.30453404318874e-08 - (8.67769362110135e-10 * fConst3));
	fConst5 = (2.65226702159437e-08 + (fConst0 * (6.86809013445937e-09 + fConst1)));
	fConst6 = (1.0 / fConst5);
	fConst7 = (8.67101574539126e-07 * fConst0);
	fConst8 = (0.00401435914138484 - fConst7);
	fConst9 = ((3.68688858465455e-10 * fConst3) - 0.00316091270975185);
	fConst10 = (3.68688858465455e-10 * fConst0);
	fConst11 = (0.00486780557301784 + (fConst0 * (fConst10 - 3.03485551088694e-06)));
	fConst12 = (7.37377716930911e-10 * fConst3);
	fConst13 = (0.00973561114603569 - fConst12);
	fConst14 = (1.0 / (0.00486780557301784 + (fConst0 * (3.03485551088694e-06 + fConst10))));
	fConst15 = (7.55757331680132e-11 * fConst0);
	fConst16 = (0.000114185647251642 + (fConst0 * (fConst15 - 8.45438325675249e-07)));
	fConst17 = (1.6908766513505e-06 * fConst0);
	fConst18 = (0.00045674258900657 - fConst17);
	fConst19 = (0.000685113883509854 - (1.51151466336026e-10 * fConst3));
	fConst20 = (0.00045674258900657 + fConst17);
	fConst21 = (1.0 / (0.000114185647251642 + (fConst0 * (8.45438325675249e-07 + fConst15))));
	fConst22 = (3.920487958595e-10 * fConst0);
	fConst23 = (0.000489785157611555 + (fConst0 * (fConst22 - 2.00478727462711e-06)));
	fConst24 = (0.000979570315223111 - (7.84097591718999e-10 * fConst3));
	fConst25 = (1.0 / (0.000489785157611555 + (fConst0 * (2.00478727462711e-06 + fConst22))));
	fConst26 = (1.2821120020393e-10 * fConst0);
	fConst27 = (6.26521815410076e-07 + fConst26);
	fConst28 = (1.13446519814126e-09 * fConst0);
	fConst29 = (0 - (2.89110812782566e-06 + fConst28));
	fConst30 = (1.12312054615984e-09 * fConst0);
	fConst31 = (2.8621970465474e-06 + fConst30);
	fConst32 = (2.26293387153501e-12 * fConst0);
	fConst33 = (1.17905906929765e-05 + fConst32);
	fConst34 = (2.26293387153501e-14 * fConst0);
	fConst35 = (1.17905906929765e-07 + fConst34);
	fConst36 = (2.89110812782566e-06 - fConst28);
	fConst37 = (fConst30 - 2.8621970465474e-06);
	fConst38 = (fConst26 - 6.26521815410076e-07);
	fConst39 = (2.08287704934496e-05 * fConst0);
	fConst40 = (0.000219016314271736 - fConst39);
	fConst41 = (1.0 / (0.000219016314271736 + fConst39));
	fConst42 = (3.7454979802542e-06 * fConst0);
	fConst43 = (0 - fConst42);
	fConst44 = (fConst32 - 1.17905906929765e-05);
	fConst45 = (fConst34 - 1.17905906929765e-07);
	fConst46 = (4.68362091734077e-13 * fConst0);
	fConst47 = (fConst0 * (fConst46 - 7.44521670106066e-07));
	fConst48 = (0 - (1.48904334021213e-06 * fConst0));
	fConst49 = (0 - (9.36724183468154e-13 * fConst3));
	fConst50 = (7.44521670106066e-07 + fConst46);
	fConst51 = (7.66731214399861e-12 * fConst0);
	fConst52 = (fConst0 * (3.99490857178962e-05 + fConst51));
	fConst53 = (0 - (1.53346242879972e-11 * fConst3));
	fConst54 = (fConst0 * (fConst51 - 3.99490857178962e-05));
	fConst55 = (0 - (0.00632182541950369 + fConst12));
	fConst56 = (0.00401435914138484 + fConst7);
	fConst57 = (fConst3 / fConst5);
	clear_state_f();
}

void Dsp::init_static(unsigned int samplingFreq, PluginDef *p)
{
	static_cast<Dsp*>(p)->init(samplingFreq);
}

void always_inline Dsp::compute(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0)
{
	FAUSTFLOAT buf[smp.max_out_count(count)];
	int ReCount = smp.up(count, input0, buf);
	double 	fSlow0 = (0.007000000000000006 * double(fslider0));
	double 	fSlow1 = (0.007000000000000006 * double(fslider1));
	double 	fSlow2 = (0.007000000000000006 * double(fslider2));
	for (int i=0; i<ReCount; i++) {
		fRec0[0] = ((0.993 * fRec0[1]) + fSlow0);
		double fTemp0 = (0 - (1.74325899023428e-09 * fRec0[0]));
		fRec2[0] = ((0.993 * fRec2[1]) + fSlow1);
		double fTemp1 = (fConst9 * fRec2[0]);
		fRec7[0] = ((0.993 * fRec7[1]) + fSlow2);
		double fTemp2 = (0.000146000960455196 + (fConst0 * ((fRec7[0] * (fConst31 + (fConst29 * fRec7[0]))) + fConst27)));
		fRec9[0] = ((double)buf[i] - (fConst41 * ((fConst40 * fRec9[2]) + (0.000438032628543473 * fRec9[1]))));
		fRec8[0] = ((fConst41 * ((fConst43 * fRec9[2]) + (fConst42 * fRec9[0]))) - (((fRec8[1] * (0.000292001920910392 + (fConst3 * ((fRec7[0] * ((2.26893039628251e-09 * fRec7[0]) - 2.24624109231969e-09)) - 2.5642240040786e-10)))) + (fRec8[2] * (0.000146000960455196 + (fConst0 * (fConst38 + (fRec7[0] * (fConst37 + (fConst36 * fRec7[0])))))))) / fTemp2));
		fRec6[0] = (min(0.801341155829, max(-0.674681752538, (fConst0 * ((((fRec8[0] * (fConst45 + (fConst44 * fRec7[0]))) + (fConst0 * (fRec8[1] * ((0 - (4.52586774307001e-12 * fRec7[0])) - 4.52586774307001e-14)))) + (fRec8[2] * (fConst35 + (fConst33 * fRec7[0])))) / fTemp2)))) - (fConst21 * ((((fConst20 * fRec6[1]) + (fConst19 * fRec6[2])) + (fConst18 * fRec6[3])) + (fConst16 * fRec6[4]))));
		fRec5[0] = ((fConst21 * ((((fConst0 * ((fConst50 * fRec6[0]) + (1.48904334021213e-06 * fRec6[1]))) + (fConst49 * fRec6[2])) + (fConst48 * fRec6[3])) + (fConst47 * fRec6[4]))) - (fConst25 * ((fConst24 * fRec5[1]) + (fConst23 * fRec5[2]))));
		fRec4[0] = (min(0.801341155829, max(-0.674681752538, (fConst25 * (((fConst54 * fRec5[0]) + (fConst53 * fRec5[1])) + (fConst52 * fRec5[2]))))) - (fConst21 * ((((fConst20 * fRec4[1]) + (fConst19 * fRec4[2])) + (fConst18 * fRec4[3])) + (fConst16 * fRec4[4]))));
		fRec3[0] = ((fConst21 * ((((fConst0 * ((fConst50 * fRec4[0]) + (1.48904334021213e-06 * fRec4[1]))) + (fConst49 * fRec4[2])) + (fConst48 * fRec4[3])) + (fConst47 * fRec4[4]))) - (fConst14 * ((fConst13 * fRec3[1]) + (fConst11 * fRec3[2]))));
		fRec1[0] = ((fConst14 * (((fRec3[0] * (fTemp1 + fConst56)) + (fRec3[1] * (0.00802871828276969 + (fConst55 * fRec2[0])))) + (fRec3[2] * (fTemp1 + fConst8)))) - (fConst6 * ((fConst4 * fRec1[1]) + (fConst2 * fRec1[2]))));
		buf[i] = (FAUSTFLOAT)(fConst57 * (((fRec1[0] * fTemp0) + (3.48651798046856e-09 * (fRec0[0] * fRec1[1]))) + (fRec1[2] * fTemp0)));
		// post processing
		fRec1[2] = fRec1[1]; fRec1[1] = fRec1[0];
		fRec3[2] = fRec3[1]; fRec3[1] = fRec3[0];
		for (int i=4; i>0; i--) fRec4[i] = fRec4[i-1];
		fRec5[2] = fRec5[1]; fRec5[1] = fRec5[0];
		for (int i=4; i>0; i--) fRec6[i] = fRec6[i-1];
		fRec8[2] = fRec8[1]; fRec8[1] = fRec8[0];
		fRec9[2] = fRec9[1]; fRec9[1] = fRec9[0];
		fRec7[1] = fRec7[0];
		fRec2[1] = fRec2[0];
		fRec0[1] = fRec0[0];
	}
	smp.down(buf, output0);
}

void __rt_func Dsp::compute_static(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0, PluginDef *p)
{
	static_cast<Dsp*>(p)->compute(count, input0, output0);
}

int Dsp::register_par(const ParamReg& reg)
{
	reg.registerVar("bmp.Sustain",N_("Sustain"),"S","",&fslider2, 0.5, 0.0, 1.0, 0.01);
	reg.registerVar("bmp.Tone",N_("Tone"),"S","",&fslider1, 0.5, 0.0, 1.0, 0.01);
	reg.registerVar("bmp.Volume",N_("Volume"),"S","",&fslider0, 0.5, 0.0, 1.0, 0.01);
	return 0;
}

int Dsp::register_params_static(const ParamReg& reg)
{
	return static_cast<Dsp*>(reg.plugin)->register_par(reg);
}

const char *Dsp::glade_def = "\
<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n\
<interface>\n\
  <!-- interface-requires gxwidgets 0.0 -->\n\
  <requires lib=\"gtk+\" version=\"2.20\"/>\n\
  <!-- interface-naming-policy project-wide -->\n\
  <object class=\"GtkWindow\" id=\"window1\">\n\
    <property name=\"can_focus\">False</property>\n\
    <child>\n\
      <object class=\"GtkVBox\" id=\"vbox1\">\n\
        <property name=\"visible\">True</property>\n\
        <property name=\"can_focus\">False</property>\n\
        <child>\n\
          <object class=\"GtkHBox\" id=\"rackbox\">\n\
            <property name=\"visible\">True</property>\n\
            <property name=\"can_focus\">False</property>\n\
            <property name=\"spacing\">4</property>\n\
            <child>\n\
              <object class=\"GtkHBox\" id=\"hbox1\">\n\
                <property name=\"visible\">True</property>\n\
                <property name=\"can_focus\">False</property>\n\
                <property name=\"spacing\">10</property>\n\
                <child>\n\
                  <object class=\"GtkVBox\" id=\"vbox2\">\n\
                    <property name=\"visible\">True</property>\n\
                    <property name=\"can_focus\">False</property>\n\
                    <child>\n\
                      <object class=\"GtkLabel\" id=\"label1:rack_label\">\n\
                        <property name=\"visible\">True</property>\n\
                        <property name=\"can_focus\">False</property>\n\
                        <property name=\"label\" translatable=\"yes\">label</property>\n\
                      </object>\n\
                      <packing>\n\
                        <property name=\"expand\">False</property>\n\
                        <property name=\"fill\">False</property>\n\
                        <property name=\"position\">0</property>\n\
                      </packing>\n\
                    </child>\n\
                    <child>\n\
                      <object class=\"GxSmallKnobR\" id=\"gxbigknob1\">\n\
                        <property name=\"visible\">True</property>\n\
                        <property name=\"can_focus\">True</property>\n\
                        <property name=\"receives_default\">True</property>\n\
                        <property name=\"var_id\">bmp.Volume</property>\n\
                        <property name=\"label_ref\">label1:rack_label</property>\n\
                      </object>\n\
                      <packing>\n\
                        <property name=\"expand\">False</property>\n\
                        <property name=\"fill\">False</property>\n\
                        <property name=\"position\">1</property>\n\
                      </packing>\n\
                    </child>\n\
                  </object>\n\
                  <packing>\n\
                    <property name=\"expand\">False</property>\n\
                    <property name=\"fill\">False</property>\n\
                    <property name=\"position\">0</property>\n\
                  </packing>\n\
                </child>\n\
                <child>\n\
                  <object class=\"GtkVBox\" id=\"vbox3\">\n\
                    <property name=\"visible\">True</property>\n\
                    <property name=\"can_focus\">False</property>\n\
                    <child>\n\
                      <object class=\"GtkLabel\" id=\"label2:rack_label\">\n\
                        <property name=\"visible\">True</property>\n\
                        <property name=\"can_focus\">False</property>\n\
                        <property name=\"label\" translatable=\"yes\">label</property>\n\
                      </object>\n\
                      <packing>\n\
                        <property name=\"expand\">False</property>\n\
                        <property name=\"fill\">False</property>\n\
                        <property name=\"position\">0</property>\n\
                      </packing>\n\
                    </child>\n\
                    <child>\n\
                      <object class=\"GxMidKnob\" id=\"gxbigknob2\">\n\
                        <property name=\"visible\">True</property>\n\
                        <property name=\"can_focus\">True</property>\n\
                        <property name=\"receives_default\">True</property>\n\
                        <property name=\"var_id\">bmp.Tone</property>\n\
                        <property name=\"label_ref\">label2:rack_label</property>\n\
                      </object>\n\
                      <packing>\n\
                        <property name=\"expand\">False</property>\n\
                        <property name=\"fill\">False</property>\n\
                        <property name=\"position\">1</property>\n\
                      </packing>\n\
                    </child>\n\
                  </object>\n\
                  <packing>\n\
                    <property name=\"expand\">False</property>\n\
                    <property name=\"fill\">False</property>\n\
                    <property name=\"position\">1</property>\n\
                  </packing>\n\
                </child>\n\
                <child>\n\
                  <object class=\"GtkVBox\" id=\"vbox4\">\n\
                    <property name=\"visible\">True</property>\n\
                    <property name=\"can_focus\">False</property>\n\
                    <child>\n\
                      <object class=\"GtkLabel\" id=\"label3:rack_label\">\n\
                        <property name=\"visible\">True</property>\n\
                        <property name=\"can_focus\">False</property>\n\
                        <property name=\"label\" translatable=\"yes\">label</property>\n\
                      </object>\n\
                      <packing>\n\
                        <property name=\"expand\">False</property>\n\
                        <property name=\"fill\">False</property>\n\
                        <property name=\"position\">0</property>\n\
                      </packing>\n\
                    </child>\n\
                    <child>\n\
                      <object class=\"GxSmallKnobR\" id=\"gxbigknob3\">\n\
                        <property name=\"visible\">True</property>\n\
                        <property name=\"can_focus\">True</property>\n\
                        <property name=\"receives_default\">True</property>\n\
                        <property name=\"var_id\">bmp.Sustain</property>\n\
                        <property name=\"label_ref\">label3:rack_label</property>\n\
                      </object>\n\
                      <packing>\n\
                        <property name=\"expand\">False</property>\n\
                        <property name=\"fill\">False</property>\n\
                        <property name=\"position\">1</property>\n\
                      </packing>\n\
                    </child>\n\
                  </object>\n\
                  <packing>\n\
                    <property name=\"expand\">False</property>\n\
                    <property name=\"fill\">False</property>\n\
                    <property name=\"position\">2</property>\n\
                  </packing>\n\
                </child>\n\
              </object>\n\
              <packing>\n\
                <property name=\"expand\">True</property>\n\
                <property name=\"fill\">False</property>\n\
                <property name=\"pack_type\">end</property>\n\
                <property name=\"position\">0</property>\n\
              </packing>\n\
            </child>\n\
          </object>\n\
          <packing>\n\
            <property name=\"expand\">True</property>\n\
            <property name=\"fill\">False</property>\n\
            <property name=\"position\">0</property>\n\
          </packing>\n\
        </child>\n\
        <child>\n\
          <object class=\"GtkHBox\" id=\"minibox\">\n\
            <property name=\"visible\">True</property>\n\
            <property name=\"can_focus\">False</property>\n\
            <property name=\"spacing\">4</property>\n\
            <child>\n\
              <object class=\"GxHSlider\" id=\"gxhslider1\">\n\
                <property name=\"visible\">True</property>\n\
                <property name=\"can_focus\">True</property>\n\
                <property name=\"receives_default\">True</property>\n\
                <property name=\"round_digits\">0</property>\n\
                <property name=\"var_id\">bmp.Sustain</property>\n\
                <property name=\"show_value\">False</property>\n\
                <property name=\"value_position\">right</property>\n\
                <property name=\"value_xalign\">0.52000000000000002</property>\n\
                <property name=\"label_ref\">label0:rack_label</property>\n\
              </object>\n\
              <packing>\n\
                <property name=\"expand\">False</property>\n\
                <property name=\"fill\">False</property>\n\
                <property name=\"position\">0</property>\n\
              </packing>\n\
            </child>\n\
            <child>\n\
              <object class=\"GtkLabel\" id=\"label0:rack_label\">\n\
                <property name=\"visible\">True</property>\n\
                <property name=\"can_focus\">False</property>\n\
                <property name=\"xalign\">0</property>\n\
                <property name=\"label\" translatable=\"yes\">Drive</property>\n\
              </object>\n\
              <packing>\n\
                <property name=\"expand\">False</property>\n\
                <property name=\"fill\">False</property>\n\
                <property name=\"position\">1</property>\n\
              </packing>\n\
            </child>\n\
          </object>\n\
          <packing>\n\
            <property name=\"expand\">True</property>\n\
            <property name=\"fill\">True</property>\n\
            <property name=\"position\">1</property>\n\
          </packing>\n\
        </child>\n\
      </object>\n\
    </child>\n\
  </object>\n\
</interface>\n\
";

inline int Dsp::load_ui_f(const UiBuilder& b, int form)
{
    if (form & UI_FORM_GLADE) {
        b.load_glade(glade_def);
        return 0;
    }
    if (form & UI_FORM_STACK) {
#define PARAM(p) ("bmp" "." p)

b.openHorizontalhideBox("");
    b.create_master_slider(PARAM("Sustain"), "Sustain");
b.closeBox();
b.openHorizontalBox("");

    b.create_small_rackknobr(PARAM("Sustain"), "Sustain");
    b.create_small_rackknobr(PARAM("Tone"), "Tone");
    b.create_small_rackknobr(PARAM("Volume"), "Volume");
b.closeBox();

#undef PARAM
        return 0;
    }
	return -1;
}

int Dsp::load_ui_f_static(const UiBuilder& b, int form)
{
	return static_cast<Dsp*>(b.plugin)->load_ui_f(b, form);
}
PluginDef *plugin() {
	return new Dsp();
}

void Dsp::del_instance(PluginDef *p)
{
	delete static_cast<Dsp*>(p);
}

} // end namespace bmp
} // end namespace pluginlib
