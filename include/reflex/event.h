// -*- c++ -*-
#pragma once
#ifndef __REFLEX_EVENT_H__
#define __REFLEX_EVENT_H__


#include <reflex/defs.h>
#include <reflex/point.h>
#include <reflex/bounds.h>
#include <reflex/painter.h>


namespace Reflex
{


	class View;


	class Event
	{

		public:

			Event ();

			void block ();

			bool is_blocked () const;

		private:

			bool blocked;

	};// Event


	struct UpdateEvent : public Event
	{

		float dt;

		UpdateEvent (float dt = 0);

	};// UpdateEvent


	struct DrawEvent : public Event
	{

		View* view;

		Painter* painter;

		Bounds bounds;

		float dt, fps;

		DrawEvent (float dt = 0, float fps = 0);

	};// DrawEvent


	struct FrameEvent : public Event
	{

		Bounds frame;

		coord dx, dy;

		union
		{
			struct {coord dwidth, dheight;};
			struct {coord dw,     dh;};
		};

		float angle, dangle;

		FrameEvent (
			const Bounds& frame = 0, coord dx = 0, coord dy = 0, coord dwidth = 0, coord dheight = 0,
			float angle = 0, float dangle = 0);

		FrameEvent (
			const Bounds& frame, const Bounds& prev_frame,
			float angle = 0, float prev_angle = 0);

		bool is_move () const;

		bool is_resize () const;

		bool is_rotate () const;

	};// FrameEvent


	struct ScrollEvent : public Event
	{

		union
		{
			struct {coord x, y, z;};
			Coord3 scroll_;
		};

		union
		{
			struct {coord dx, dy, dz;};
			Coord3 delta_;
		};

		ScrollEvent ();

		ScrollEvent (coord x, coord y, coord z, coord dx, coord dy, coord dz);

		      Point& scroll ();

		const Point& scroll () const;

		      Point& delta ();

		const Point& delta () const;

	};// ScrollEvent


	struct FocusEvent : public Event
	{

		enum Type {NONE = 0, FOCUS, BLUR};

		Type type;

		View *focus, *last;

		FocusEvent ();

		FocusEvent (Type type, View* focus, View* last);

	};// FocusEvent


	struct KeyEvent : public Event
	{

		enum Type {NONE = 0, DOWN, UP};

		Type type;

		String chars;

		int code;

		uint modifiers;

		int repeat;

		bool capture;

		KeyEvent ();

		KeyEvent (
			Type type, const char* chars, int code,
			uint modifiers = 0, int repeat = 0);

	};// KeyEvent


	struct PointerEvent : public Event
	{

		enum Type {NONE = 0, DOWN, UP, MOVE};

		enum {MAX = 10};

		Type type;

		uint pointer_type;

		size_t size;

		uint modifiers, count;

		bool drag, capture;

		union
		{
			struct {coord x, y, z;};
			Coord3 positions[MAX];
		};

		PointerEvent ();

		PointerEvent (
			Type type, uint pointer_type, coord x, coord y,
			uint modifiers = 0, uint count = 1, bool drag = false);

		PointerEvent (
			Type type, uint pointer_type, const Point* positions, size_t size,
			uint modifiers = 0, uint count = 1, bool drag = false);

		      Point& position (size_t i = 0);

		const Point& position (size_t i = 0) const;

		      Point& operator [] (size_t i);

		const Point& operator [] (size_t i) const;

	};// PointerEvent


	struct WheelEvent : public Event
	{

		union
		{
			struct {coord dx, dy, dz;};
			Coord3 delta_;
		};

		union
		{
			struct {coord x, y, z;};
			Coord3 position_;
		};

		uint modifiers;

		WheelEvent ();

		WheelEvent (
			coord dx, coord dy, coord dz, coord x = 0, coord y = 0, coord z = 0,
			uint modifiers = 0);

		      Point& delta ();

		const Point& delta () const;

		      Point& position ();

		const Point& position () const;

	};// WheelEvent


	struct CaptureEvent : public Event
	{

		uint begin, end;

		CaptureEvent ();

		CaptureEvent (uint begin, uint end);

	};// CaptureEvent


	struct ContactEvent : public Event
	{

		enum Type {NONE = 0, BEGIN, END};

		Type type;

		View* view;

		ContactEvent ();

		ContactEvent (Type type, View* view);

	};// ContactEvent


}// Reflex


#endif//EOH
