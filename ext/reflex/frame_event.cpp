#include "reflex/ruby/event.h"


#include <rucy.h>
#include "rays/ruby/point.h"
#include "rays/ruby/bounds.h"
#include "defs.h"


using namespace Rucy;

using Reflex::coord;


RUCY_DEFINE_VALUE_FROM_TO(Reflex::FrameEvent)

#define THIS  to<Reflex::FrameEvent*>(self)

#define CHECK RUCY_CHECK_OBJ(Reflex::FrameEvent, self)


static
RUCY_DEF_ALLOC(alloc, klass)
{
	return new_type<Reflex::FrameEvent>(klass);
}
RUCY_END

static
RUCY_DEFN(initialize)
{
	CHECK;
	check_arg_count(__FILE__, __LINE__, "FrameEvent#initialize", argc, 0, 1, 2, 3, 4, 5);

	THIS->frame   = (argc >= 1) ? to<Rays::Bounds&>(argv[0]) : Rays::Bounds(0);
	THIS->dx      = (argc >= 2) ? to<coord>(argv[1]) : 0;
	THIS->dy      = (argc >= 3) ? to<coord>(argv[2]) : 0;
	THIS->dwidth  = (argc >= 4) ? to<coord>(argv[3]) : 0;
	THIS->dheight = (argc >= 5) ? to<coord>(argv[4]) : 0;

	return rb_call_super(0, NULL);
}
RUCY_END

static
RUCY_DEF1(initialize_copy, obj)
{
	CHECK;
	*THIS = to<Reflex::FrameEvent&>(obj);
	return self;
}
RUCY_END

static
RUCY_DEF0(frame)
{
	CHECK;
	return value(THIS->frame);
}
RUCY_END

static
RUCY_DEF0(dx)
{
	CHECK;
	return value(THIS->dx);
}
RUCY_END

static
RUCY_DEF0(dy)
{
	CHECK;
	return value(THIS->dy);
}
RUCY_END

static
RUCY_DEF0(dwidth)
{
	CHECK;
	return value(THIS->dwidth);
}
RUCY_END

static
RUCY_DEF0(dheight)
{
	CHECK;
	return value(THIS->dheight);
}
RUCY_END

static
RUCY_DEF0(dposition)
{
	CHECK;
	return value(Rays::Point(THIS->dx, THIS->dy));
}
RUCY_END

static
RUCY_DEF0(dsize)
{
	CHECK;
	return value(Rays::Point(THIS->dw, THIS->dh));
}
RUCY_END


static Class cFrameEvent;

void
Init_frame_event ()
{
	Module mReflex = define_module("Reflex");

	cFrameEvent = mReflex.define_class("FrameEvent", Reflex::event_class());
	cFrameEvent.define_alloc_func(alloc);
	cFrameEvent.define_private_method("initialize", initialize);
	cFrameEvent.define_private_method("initialize_copy", initialize_copy);
	cFrameEvent.define_method("frame", frame);
	cFrameEvent.define_method("dx", dx);
	cFrameEvent.define_method("dy", dy);
	cFrameEvent.define_method("dwidth",  dwidth);
	cFrameEvent.define_method("dheight", dheight);
	cFrameEvent.define_method("dposition", dposition);
	cFrameEvent.define_method("dsize",     dsize);
}


namespace Reflex
{


	Class
	frame_event_class ()
	{
		return cFrameEvent;
	}


}// Reflex
