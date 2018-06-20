#ifndef MOVEWIDGET_H
#define MOVEWIDGET_H

#include <QWidget>
#include <QEvent>

class MoveWidget : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(bool Full_Screen READ fullScreen WRITE setFullScreen DESIGNABLE true USER true)
public:
    explicit MoveWidget(QWidget *parent = 0);

public:
    bool fullScreen() const;
    void setFullScreen(bool fullscreen);

signals:

public slots:

protected:
    void mouseMoveEvent(QMouseEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void mouseDoubleClickEvent(QMouseEvent *e);

private:
    QPoint  m_mouse_pos;
    bool    m_pressed;
    bool    m_fullscreen;
};

#endif // MOVEWIDGET_H
