// -*- c++ -*-
#pragma once
#ifndef __REFLEX_SRC_EVENT_H__
#define __REFLEX_SRC_EVENT_H__


#include <functional>
#include "reflex/event.h"


namespace Reflex
{


	void DrawEvent_set_view    (DrawEvent* pthis, View* view);

	void DrawEvent_set_painter (DrawEvent* pthis, Painter* painter);

	void DrawEvent_set_bounds  (DrawEvent* pthis, const Bounds& bounds);


	uint KeyEvent_get_modifiers ();

	void KeyEvent_set_chars (KeyEvent* pthis, const char* chars);

	void KeyEvent_set_captured (KeyEvent* pthis, bool captured);


	void PointerEvent_add_pointer (PointerEvent* pthis, const Pointer& pointer);

	void PointerEvent_erase_pointer (PointerEvent* pthis, Pointer::ID id);

	Pointer& PointerEvent_pointer_at (PointerEvent* pthis, size_t index);

	void PointerEvent_each_pointer (
		const PointerEvent* pthis, std::function<void(const Pointer&)> fun);

	void PointerEvent_increment_view_indices (PointerEvent* pthis);

	void PointerEvent_set_captured (PointerEvent* pthis, bool captured);

	void PointerEvent_update_for_child_view (
		PointerEvent* pthis, const View* view);

	void PointerEvent_update_for_capturing_view (
		PointerEvent* pthis, const View* view);


	void WheelEvent_set_position (WheelEvent* pthis, const Point& position);


	bool MIDIEvent_to_note_event (NoteEvent* result, const MIDIEvent& event);

	bool MIDIEvent_to_control_change_event (
		ControlChangeEvent* result, const MIDIEvent& event);

	void MIDIEvent_set_captured (MIDIEvent* pthis, bool captured);


	void NoteEvent_set_captured (NoteEvent* pthis, bool captured);


	void ControlChangeEvent_set_captured (ControlChangeEvent* pthis, bool captured);


}// Reflex


#endif//EOH
