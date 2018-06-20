#include "movewidget.h"
#include <QMouseEvent>
#include <QApplication>

MoveWidget::MoveWidget(QWidget *parent) :
    QWidget(parent),
    m_pressed(false),
    m_fullscreen(false)
{
    setMouseTracking(true);
}

bool MoveWidget::fullScreen() const
{
    return m_fullscreen;
}

void MoveWidget::setFullScreen(bool fullscreen)
{
    m_fullscreen = fullscreen;
}

void MoveWidget::mouseMoveEvent(QMouseEvent *e)
{
    if (m_pressed)
    {
        if (QApplication::activeWindow()->isMaximized())
        {
            QPoint _pos( QApplication::activeWindow()->pos() );
            QApplication::activeWindow()->showNormal();
            QApplication::processEvents();
            QSize _size(QApplication::activeWindow()->size());
            QApplication::activeWindow()->move(e->globalPos().x() - _size.width() * 0.5, _pos.y() + e->globalPos().y() - m_mouse_pos.y());
            m_mouse_pos = e->globalPos();
        }
        else
        {
            QApplication::activeWindow()->move(QApplication::activeWindow()->pos() + e->globalPos() - m_mouse_pos);
            m_mouse_pos = e->globalPos();
        }
    }
}

void MoveWidget::mousePressEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton)
    {
        m_mouse_pos = e->globalPos();
        m_pressed = true;
    }
}

void MoveWidget::mouseReleaseEvent(QMouseEvent *e)
{
    (void)(e);
    m_pressed = false;
}

void MoveWidget::mouseDoubleClickEvent(QMouseEvent* /*e*/)
{
    if (!m_fullscreen)
        return;
    if (QApplication::activeWindow()->isMaximized())
        QApplication::activeWindow()->showNormal();
    else
        QApplication::activeWindow()->showMaximized();
    QApplication::processEvents();
}
