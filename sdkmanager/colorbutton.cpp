#include "colorbutton.h"

template<typename T>
T clamp(const T &n, const T& lower, const T& upper) {
    return std::max(lower, std::min(n, upper));
}
#define CLAMP clamp

ColorButton::ColorButton(QWidget *parent) :
    QPushButton(parent),
    m_mode(Mode1)
{
} // ctor

QColor ColorButton::backgroundColor1() const
{
    return m_bg_color[0].normal;
} // backgroundColor1

QColor ColorButton::backgroundColor2() const
{
    return m_bg_color[1].normal;
} // backgroundColor2

QColor ColorButton::backgroundColor3() const
{
    return m_bg_color[2].normal;
} // backgroundColor3

QColor ColorButton::backgroundColor4() const
{
    return m_bg_color[3].normal;
} // backgroundColor4

QColor ColorButton::backgroundColor5() const
{
    return m_bg_color[4].normal;
} // backgroundColor5

QColor ColorButton::foreColor1() const
{
    return m_color[0].normal;
} // foreColor1

QColor ColorButton::foreColor2() const
{
    return m_color[1].normal;
} // foreColor2

QColor ColorButton::foreColor3() const
{
    return m_color[2].normal;
} // foreColor3

QColor ColorButton::foreColor4() const
{
    return m_color[3].normal;
} // foreColor4

QColor ColorButton::foreColor5() const
{
    return m_color[4].normal;
} // foreColor5

QColor ColorButton::disabledBackgroundColor1() const
{
    return m_bg_color[0].disable;
} // disabledBackgroundColor1

QColor ColorButton::disabledBackgroundColor2() const
{
    return m_bg_color[1].disable;
} // disabledBackgroundColor2

QColor ColorButton::disabledBackgroundColor3() const
{
    return m_bg_color[2].disable;
} // disabledBackgroundColor3

QColor ColorButton::disabledBackgroundColor4() const
{
    return m_bg_color[3].disable;
} // disabledBackgroundColor4

QColor ColorButton::disabledBackgroundColor5() const
{
    return m_bg_color[4].disable;
} // disabledBackgroundColor5

QColor ColorButton::disabledColor1() const
{
    return m_color[0].disable;
} // disabledColor1

QColor ColorButton::disabledColor2() const
{
    return m_color[1].disable;
} // disabledColor2

QColor ColorButton::disabledColor3() const
{
    return m_color[2].disable;
} // disabledColor3

QColor ColorButton::disabledColor4() const
{
    return m_color[3].disable;
} // disabledColor4

QColor ColorButton::disabledColor5() const
{
    return m_color[4].disable;
} // disabledColor5

void ColorButton::setBackgroundColor1(const QColor &color)
{
    m_bg_color[0].normal = color;
    m_bg_color[0].hover.setRgb(CLAMP(color.red() + 16, 0, 255), CLAMP(color.green() + 16, 0, 255), CLAMP(color.blue() + 16, 0, 255));
    m_bg_color[0].pressed.setRgb(CLAMP(color.red() - 16, 0, 255), CLAMP(color.green() - 16, 0, 255), CLAMP(color.blue() - 16, 0, 255));
    updateStyleSheet(0);
} // setBackgroundColor1

void ColorButton::setBackgroundColor2(const QColor &color)
{
    m_bg_color[1].normal = color;
    m_bg_color[1].hover.setRgb(CLAMP(color.red() + 16, 0, 255), CLAMP(color.green() + 16, 0, 255), CLAMP(color.blue() + 16, 0, 255));
    m_bg_color[1].pressed.setRgb(CLAMP(color.red() - 16, 0, 255), CLAMP(color.green() - 16, 0, 255), CLAMP(color.blue() - 16, 0, 255));
    updateStyleSheet(1);
} // setBackgroundColor2

void ColorButton::setBackgroundColor3(const QColor &color)
{
    m_bg_color[2].normal = color;
    m_bg_color[2].hover.setRgb(CLAMP(color.red() + 16, 0, 255), CLAMP(color.green() + 16, 0, 255), CLAMP(color.blue() + 16, 0, 255));
    m_bg_color[2].pressed.setRgb(CLAMP(color.red() - 16, 0, 255), CLAMP(color.green() - 16, 0, 255), CLAMP(color.blue() - 16, 0, 255));
    updateStyleSheet(2);
} // setBackgroundColor3

void ColorButton::setBackgroundColor4(const QColor &color)
{
    m_bg_color[3].normal = color;
    m_bg_color[3].hover.setRgb(CLAMP(color.red() + 16, 0, 255), CLAMP(color.green() + 16, 0, 255), CLAMP(color.blue() + 16, 0, 255));
    m_bg_color[3].pressed.setRgb(CLAMP(color.red() - 16, 0, 255), CLAMP(color.green() - 16, 0, 255), CLAMP(color.blue() - 16, 0, 255));
    updateStyleSheet(3);
} // setBackgroundColor4

void ColorButton::setBackgroundColor5(const QColor &color)
{
    m_bg_color[4].normal = color;
    m_bg_color[4].hover.setRgb(CLAMP(color.red() + 16, 0, 255), CLAMP(color.green() + 16, 0, 255), CLAMP(color.blue() + 16, 0, 255));
    m_bg_color[4].pressed.setRgb(CLAMP(color.red() - 16, 0, 255), CLAMP(color.green() - 16, 0, 255), CLAMP(color.blue() - 16, 0, 255));
    updateStyleSheet(4);
} // setBackgroundColor5

void ColorButton::setForeColor1(const QColor &color)
{
    m_color[0].normal = color;
    m_color[0].hover.setRgb(CLAMP(color.red() + 16, 0, 255), CLAMP(color.green() + 16, 0, 255), CLAMP(color.blue() + 16, 0, 255));
    m_color[0].pressed.setRgb(CLAMP(color.red() - 16, 0, 255), CLAMP(color.green() - 16, 0, 255), CLAMP(color.blue() - 16, 0, 255));
    updateStyleSheet(0);
} // setForeColor1

void ColorButton::setForeColor2(const QColor &color)
{
    m_color[1].normal = color;
    m_color[1].hover.setRgb(CLAMP(color.red() + 16, 0, 255), CLAMP(color.green() + 16, 0, 255), CLAMP(color.blue() + 16, 0, 255));
    m_color[1].pressed.setRgb(CLAMP(color.red() - 16, 0, 255), CLAMP(color.green() - 16, 0, 255), CLAMP(color.blue() - 16, 0, 255));
    updateStyleSheet(1);
} // setForeColor2

void ColorButton::setForeColor3(const QColor &color)
{
    m_color[2].normal = color;
    m_color[2].hover.setRgb(CLAMP(color.red() + 16, 0, 255), CLAMP(color.green() + 16, 0, 255), CLAMP(color.blue() + 16, 0, 255));
    m_color[2].pressed.setRgb(CLAMP(color.red() - 16, 0, 255), CLAMP(color.green() - 16, 0, 255), CLAMP(color.blue() - 16, 0, 255));
    updateStyleSheet(2);
} // setForeColor3

void ColorButton::setForeColor4(const QColor &color)
{
    m_color[3].normal = color;
    m_color[3].hover.setRgb(CLAMP(color.red() + 16, 0, 255), CLAMP(color.green() + 16, 0, 255), CLAMP(color.blue() + 16, 0, 255));
    m_color[3].pressed.setRgb(CLAMP(color.red() - 16, 0, 255), CLAMP(color.green() - 16, 0, 255), CLAMP(color.blue() - 16, 0, 255));
    updateStyleSheet(3);
} // setForeColor4

void ColorButton::setForeColor5(const QColor &color)
{
    m_color[4].normal = color;
    m_color[4].hover.setRgb(CLAMP(color.red() + 16, 0, 255), CLAMP(color.green() + 16, 0, 255), CLAMP(color.blue() + 16, 0, 255));
    m_color[4].pressed.setRgb(CLAMP(color.red() - 16, 0, 255), CLAMP(color.green() - 16, 0, 255), CLAMP(color.blue() - 16, 0, 255));
    updateStyleSheet(4);
} // setForeColor5

void ColorButton::setDisabledBackgroundColor1(const QColor &color)
{
    m_bg_color[0].disable = color;
    updateStyleSheet(0);
} // setDisabledBackgroundColor1

void ColorButton::setDisabledBackgroundColor2(const QColor &color)
{
    m_bg_color[1].disable = color;
    updateStyleSheet(1);
} // setDisabledBackgroundColor2

void ColorButton::setDisabledBackgroundColor3(const QColor &color)
{
    m_bg_color[2].disable = color;
    updateStyleSheet(2);
} // setDisabledBackgroundColor3

void ColorButton::setDisabledBackgroundColor4(const QColor &color)
{
    m_bg_color[3].disable = color;
    updateStyleSheet(3);
} // setDisabledBackgroundColor4

void ColorButton::setDisabledBackgroundColor5(const QColor &color)
{
    m_bg_color[4].disable = color;
    updateStyleSheet(4);
} // setDisabledBackgroundColor5

void ColorButton::setDisabledColor1(const QColor &color)
{
    m_color[0].disable = color;
    updateStyleSheet(0);
} // setDisabledColor1

void ColorButton::setDisabledColor2(const QColor &color)
{
    m_color[1].disable = color;
    updateStyleSheet(1);
} // setDisabledColor2

void ColorButton::setDisabledColor3(const QColor &color)
{
    m_color[2].disable = color;
    updateStyleSheet(2);
} // setDisabledColor3

void ColorButton::setDisabledColor4(const QColor &color)
{
    m_color[3].disable = color;
    updateStyleSheet(3);
} // setDisabledColor4

void ColorButton::setDisabledColor5(const QColor &color)
{
    m_color[4].disable = color;
    updateStyleSheet(4);
} // setDisabledColor5

ColorButton::ModeType ColorButton::mode() const
{
    return m_mode;
} // mode

void ColorButton::setMode(ModeType mode)
{
    m_mode = mode;
    if ((int)mode > Mode5)
    {
        setStyleSheet("");
        return;
    }
    setStyleSheet(m_style[(int)mode]);
} // setMode

void ColorButton::showEvent(QShowEvent *)
{
    setMode(m_mode);
} // showEvent

void ColorButton::updateStyleSheet(int index)
{
    m_style[index] = QString(
        "QPushButton { background-color: rgb(%1, %2, %3); color: rgb(%4, %5, %6); } \n"
        "QPushButton:hover { background-color: rgb(%7, %8, %9); color: rgb(%10, %11, %12); } \n"
        "QPushButton:pressed { background-color: rgb(%13, %14, %15); color: rgb(%16, %17, %18); } \n"
        "QPushButton:disabled { background-color: rgb(%19, %20, %21); color: rgb(%22, %23, %24); }").
        arg(m_bg_color[index].normal.red()).arg(m_bg_color[index].normal.green()).arg(m_bg_color[index].normal.blue()).
        arg(m_color[index].normal.red()).arg(m_color[index].normal.green()).arg(m_color[index].normal.blue()).
        arg(m_bg_color[index].hover.red()).arg(m_bg_color[index].hover.green()).arg(m_bg_color[index].hover.blue()).
        arg(m_color[index].hover.red()).arg(m_color[index].hover.green()).arg(m_color[index].hover.blue()).
        arg(m_bg_color[index].pressed.red()).arg(m_bg_color[index].pressed.green()).arg(m_bg_color[index].pressed.blue()).
        arg(m_color[index].pressed.red()).arg(m_color[index].pressed.green()).arg(m_color[index].pressed.blue()).
        arg(m_bg_color[index].disable.red()).arg(m_bg_color[index].disable.green()).arg(m_bg_color[index].disable.blue()).
        arg(m_color[index].disable.red()).arg(m_color[index].disable.green()).arg(m_color[index].disable.blue());
} // updateStyleSheet
