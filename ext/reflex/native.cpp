#include <rucy.h>
#include "defs.h"


using namespace Rucy;


void Init_reflex ();

void Init_selector ();
void Init_style ();
void Init_style_length ();
void Init_style_length2 ();
void Init_style_length4 ();

void Init_event ();
void Init_update_event ();
void Init_draw_event ();
void Init_frame_event ();
void Init_scroll_event ();
void Init_focus_event ();
void Init_key_event ();
void Init_pointer_event ();
void Init_wheel_event ();
void Init_capture_event ();
void Init_contact_event ();

void Init_body ();
void Init_fixture ();

void Init_application ();
void Init_window ();
void Init_view ();

void Init_image_view ();

void Init_shape_view ();
void Init_rect_shape ();
void Init_ellipse_shape ();
void Init_arc_shape ();


extern "C" void
#ifdef COCOAPODS
	Init_reflex_native ()
#else
	Init_native ()
#endif
{
	RUCY_TRY

	Rucy::init();

	Init_reflex();

	Init_selector();
	Init_style();
	Init_style_length();
	Init_style_length2();
	Init_style_length4();

	Init_event();
	Init_update_event();
	Init_draw_event();
	Init_frame_event();
	Init_scroll_event();
	Init_focus_event();
	Init_key_event();
	Init_pointer_event();
	Init_wheel_event();
	Init_capture_event();
	Init_contact_event();

	Init_body();
	Init_fixture();

	Init_application();
	Init_window();
	Init_view();

	Init_image_view();

	Init_shape_view();
	Init_rect_shape();
	Init_ellipse_shape();
	Init_arc_shape();

	RUCY_CATCH
}
