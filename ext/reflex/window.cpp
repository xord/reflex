#include "reflex/ruby/window.h"


#include <rucy.h>
#include <rays/ruby/bounds.h>
#include <rays/ruby/painter.h>
#include "reflex/ruby/view.h"


using namespace Rucy;

using Reflex::coord;


RUCY_DEFINE_WRAPPER_VALUE_FROM_TO(Reflex::Window)

#define THIS      to<Reflex::Window*>(self)

#define CHECK     RUCY_CHECK_OBJECT(Reflex::Window, self)

#define CALL(fun) RUCY_WRAPPER_CALL(Reflex::Window, THIS, fun)


static
RUCY_DEF_ALLOC(alloc, klass)
{
	return value(new Reflex::RubyWindow<Reflex::Window>, klass);
}
RUCY_END

static
RUCY_DEF0(show)
{
	CHECK;
	THIS->show();
	return self;
}
RUCY_END

static
RUCY_DEF0(hide)
{
	CHECK;
	THIS->hide();
	return self;
}
RUCY_END

static
RUCY_DEF0(close)
{
	CHECK;
	THIS->close();
	return self;
}
RUCY_END

static
RUCY_DEF0(redraw)
{
	CHECK;
	THIS->redraw();
	return self;
}
RUCY_END

static
RUCY_DEF1(set_title, title)
{
	CHECK;
	THIS->set_title(title.c_str());
	return title;
}
RUCY_END

static
RUCY_DEF0(get_title)
{
	CHECK;
	return value(THIS->title());
}
RUCY_END

static
RUCY_DEF1(set_frame, arg)
{
	CHECK;
	THIS->set_frame(to<Rays::Bounds>(arg));
}
RUCY_END

static
RUCY_DEF0(get_frame)
{
	CHECK;
	return value(THIS->frame());
}
RUCY_END

static
RUCY_DEF0(hidden)
{
	CHECK;
	return value(THIS->hidden());
}
RUCY_END

static
RUCY_DEF0(root)
{
	CHECK;
	return value(THIS->root());
}
RUCY_END

static
RUCY_DEF0(focus)
{
	CHECK;
	return value(THIS->focus());
}
RUCY_END

static
RUCY_DEF0(painter)
{
	CHECK;
	return value(THIS->painter());
}
RUCY_END

static
RUCY_DEF1(on_show, event)
{
	CHECK;

	RUCY_SYM(call_show_block);
	self.call(call_show_block);

	CALL(on_show(to<Reflex::Event*>(event)));
}
RUCY_END

static
RUCY_DEF1(on_hide, event)
{
	CHECK;
	CALL(on_hide(to<Reflex::Event*>(event)));
}
RUCY_END

static
RUCY_DEF1(on_close, event)
{
	CHECK;
	CALL(on_close(to<Reflex::Event*>(event)));
}
RUCY_END

static
RUCY_DEF1(on_update, event)
{
	CHECK;
	CALL(on_update(to<Reflex::UpdateEvent*>(event)));
}
RUCY_END

static
RUCY_DEF1(on_draw, event)
{
	CHECK;
	CALL(on_draw(to<Reflex::DrawEvent*>(event)));
}
RUCY_END

static
RUCY_DEF1(on_move, event)
{
	CHECK;
	CALL(on_move(to<Reflex::FrameEvent*>(event)));
}
RUCY_END

static
RUCY_DEF1(on_resize, event)
{
	CHECK;
	CALL(on_resize(to<Reflex::FrameEvent*>(event)));
}
RUCY_END

static
RUCY_DEF1(on_key, event)
{
	CHECK;
	CALL(on_key(to<Reflex::KeyEvent*>(event)));
}
RUCY_END

static
RUCY_DEF1(on_key_down, event)
{
	CHECK;
	CALL(on_key_down(to<Reflex::KeyEvent*>(event)));
}
RUCY_END

static
RUCY_DEF1(on_key_up, event)
{
	CHECK;
	CALL(on_key_up(to<Reflex::KeyEvent*>(event)));
}
RUCY_END

static
RUCY_DEF1(on_pointer, event)
{
	CHECK;
	CALL(on_pointer(to<Reflex::PointerEvent*>(event)));
}
RUCY_END

static
RUCY_DEF1(on_pointer_down, event)
{
	CHECK;
	CALL(on_pointer_down(to<Reflex::PointerEvent*>(event)));
}
RUCY_END

static
RUCY_DEF1(on_pointer_up, event)
{
	CHECK;
	CALL(on_pointer_up(to<Reflex::PointerEvent*>(event)));
}
RUCY_END

static
RUCY_DEF1(on_pointer_move, event)
{
	CHECK;
	CALL(on_pointer_move(to<Reflex::PointerEvent*>(event)));
}
RUCY_END

static
RUCY_DEF1(on_wheel, event)
{
	CHECK;
	CALL(on_wheel(to<Reflex::WheelEvent*>(event)));
}
RUCY_END

static
RUCY_DEF_clear_override_flags(cof, Reflex::Window);


static Class cWindow;

void
Init_window ()
{
	Module mReflex = define_module("Reflex");

	cWindow = mReflex.define_class("Window");
	cWindow.define_alloc_func(alloc);
	cWindow.define_method("show", show);
	cWindow.define_method("hide", hide);
	cWindow.define_method("close", close);
	cWindow.define_method("redraw", redraw);
	cWindow.define_method("title=", set_title);
	cWindow.define_method("title", get_title);
	cWindow.define_private_method("set_frame", set_frame);
	cWindow.define_private_method("get_frame", get_frame);
	cWindow.define_method("hidden", hidden);
	cWindow.define_method("root", root);
	cWindow.define_method("focus", focus);
	cWindow.define_method("painter", painter);
	cWindow.define_method("on_show",  on_show);
	cWindow.define_method("on_hide",  on_hide);
	cWindow.define_method("on_close", on_close);
	cWindow.define_method("on_update", on_update);
	cWindow.define_method("on_draw",   on_draw);
	cWindow.define_method("on_move",   on_move);
	cWindow.define_method("on_resize", on_resize);
	cWindow.define_method("on_key",      on_key);
	cWindow.define_method("on_key_down", on_key_down);
	cWindow.define_method("on_key_up",   on_key_up);
	cWindow.define_method("on_pointer",      on_pointer);
	cWindow.define_method("on_pointer_down", on_pointer_down);
	cWindow.define_method("on_pointer_up",   on_pointer_up);
	cWindow.define_method("on_pointer_move", on_pointer_move);
	cWindow.define_method("on_wheel", on_wheel);
	cWindow.define_clear_override_flags(cof);
}


namespace Reflex
{


	Class
	window_class ()
	{
		return cWindow;
	}


}// Reflex
