/*
 * (C) 2012-2013 Marmalade.
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

//------------------------------------------------------------------------------
/*!
	\file QRectangle.h
	\brief Rectangle object intermediary.
*/
//------------------------------------------------------------------------------

#ifndef __Q_RECTANGLE_H
#define __Q_RECTANGLE_H

#include "QLines.h"

// tolua_begin
namespace quick {
// tolua_end

//------------------------------------------------------------------------------
// QRectangle
//------------------------------------------------------------------------------
/**
The Rectangle object provides the facility to draw outlined and filled rectangles.
It inherits from the Lines object, which inherits from the Vector object, which inherits from the Node object.
*/
class QRectangle : public QLines { // tolua_export
public:
    // BOUND, PRIVATE
    // tolua_begin
    virtual const char* _getToLuaClassName() { return "quick::QRectangle"; }
    std::string __tostring() { return "<>"; }
    void* __serialize() { return NULL; }
	QRectangle();
	~QRectangle();

    // BOUND, PUBLIC
    virtual void sync();
    // tolua_end

    // UNBOUND

}; // tolua_export

// tolua_begin
}
// tolua_end

#endif // __Q_RECTANGLE_H
