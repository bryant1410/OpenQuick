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
	\file QLabel.h
	\brief Label object intermediary.
*/
//------------------------------------------------------------------------------

#ifndef __Q_LABEL_H
#define __Q_LABEL_H

#include "QDefines.h"
#include "QNode.h"
#include "QFont.h"

#include "cocos2d.h"

// tolua_begin
namespace quick {
// tolua_end

//------------------------------------------------------------------------------
// CCLabelNode
//------------------------------------------------------------------------------
/**
The CCLabelNode object is used to render debug information about font strings
*/
class QLabel;
class CCLabelNode : public cocos2d::CCNode {
public:
    CCLabelNode(QLabel*label) { m_Label = label; }
	virtual void draw();
    QLabel* m_Label;
};

//------------------------------------------------------------------------------
// QLabel
//------------------------------------------------------------------------------
/**
The Label object is used to render font strings. It uses a font object as it's
source and displays a single or multiple lines of text with adjustable alignment
It inherits from the Node object.
*/
class QLabel : public QNode { // tolua_export
    friend class CCLabelNode;
public:
    // BOUND, PRIVATE
    // tolua_begin
    virtual const char* _getToLuaClassName() { return "quick::QLabel"; }
    std::string __tostring() { return "<>"; }
    void* __serialize() { return NULL; }
    QLabel();
    ~QLabel();

    // BOUND, PUBLIC
    // PAUL TO COMMENT
	void init();

    virtual void sync();
    virtual bool isPointInside(float x, float y);

    //! The displayed text
    /** The text to be displayed by the Label object */
	std::string text;

    //! The Label's font
    /** The font the label uses to render it's text with */
	QFont *font;

    //! The horizontal alignment of the label text
    /** The horizontal alignment of the text string when rendered
        Possible options are
            - "left"
            - "center" or "centre"
            - "right"
    */
	std::string hAlignment;

    //! The vertical alignment of the label text
    /** The vertical alignment of the text string when rendered
        Possible options are
            - "top"
            - "middle"
            - "bottom"
    */
	std::string vAlignment;

    /**
        If this value is 0, then the touchable area of the Label is the "text box" area, defined by x,y,w,h.
        Otherwise, the touchable area of the Label is the minimal bounding box around the rendered text itself,
        plus a border of this width in pixels. The default value is 4.
    */
    float textTouchableBorder;

    //! The top border of the rendering box.  Scales inward but can be negative.  The default is 0
    float textBorderTop;

    //! The bottom border of the rendering box.  Scales inward but can be negative.  The default is 0
    float textBorderBottom;

    //! The left border of the rendering box.  Scales inward but can be negative.  The default is 0
    float textBorderLeft;

    //! The right border of the rendering box.  Scales inward but can be negative.  The default is 0
    float textBorderRight;

    //! Horizontal font scale.  This doesn't affect the text box.  The default is 1.0
    float textXScale;

    //! Vertical font scale.  This doesn't affect the text box.  The default is 1.0
    float textYScale;

    // tolua_end

    // BOUND EXPLICITLY IN TOLUA PKG
	/** @var xText
	The x position of the rendered text
	*/
    Q_READONLY_VARIABLE( float, xText);

	/** @var yText
	The y position of the rendered text
	*/
    Q_READONLY_VARIABLE( float, yText);

	/** @var wText
	The width of the rendered text
	*/
    Q_READONLY_VARIABLE( float, wText);

	/** @var hText
	The height of the rendered text
	*/
    Q_READONLY_VARIABLE( float, hText);

    // UNBOUND
//    bool m_RenderToRectangle;

    cocos2d::CCLabelBMFont *m_CCFontNode;

	float m_CachedWidth;
    float m_CachedHeight;
    std::string m_CachedHAlignment;
	std::string m_CachedVAlignment;

    float m_CachedTextBorderTop;
    float m_CachedTextBorderBottom;
    float m_CachedTextBorderLeft;
    float m_CachedTextBorderRight;
    float m_CachedTextXScale;
    float m_CachedTextYScale;

	void GetCurrentAlignment(cocos2d::CCTextAlignment *h_alignment, cocos2d::CCVerticalTextAlignment *v_alignment) const;
    void SetAlignmentAnchors( cocos2d::CCTextAlignment h_alignment, cocos2d::CCVerticalTextAlignment v_alignment);

    void CalculateSize( void);

private:
    float GetCalculatedWidth( void)
    {
// PJC remove border clip        float width = w == 0.0f ? ((m_Parent ? m_Parent->w : 0.0f) - x) : w;
//        return width < 0.0f ? 0.0f : width;
        return w == 0.0f ? (m_Parent ? m_Parent->w : 0.0f) : w;
    }
    float GetCalculatedHeight( void)
    {
// PJC remove border clip        float height = h == 0.0f ? ((m_Parent ? m_Parent->h : 0.0f) - y) : h;
//        return height < 0.0f ? 0.0f : height;
        return h == 0.0f ? (m_Parent ? m_Parent->h : 0.0f) : h;
    }

}; // tolua_export

// tolua_begin
}
// tolua_end

#endif // __Q_LABEL_H
