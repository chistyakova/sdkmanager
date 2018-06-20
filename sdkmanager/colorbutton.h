#ifndef COLORBUTTON_H
#define COLORBUTTON_H

#include <QtWidgets/QPushButton>

class ColorButton : public QPushButton
{
    Q_OBJECT

    Q_PROPERTY(QColor backgroundColor1 READ backgroundColor1 WRITE setBackgroundColor1)
    Q_PROPERTY(QColor backgroundColor2 READ backgroundColor2 WRITE setBackgroundColor2)
    Q_PROPERTY(QColor backgroundColor3 READ backgroundColor3 WRITE setBackgroundColor3)
    Q_PROPERTY(QColor backgroundColor4 READ backgroundColor4 WRITE setBackgroundColor4)
    Q_PROPERTY(QColor backgroundColor5 READ backgroundColor5 WRITE setBackgroundColor5)
    Q_PROPERTY(QColor foreColor1 READ foreColor1 WRITE setForeColor1)
    Q_PROPERTY(QColor foreColor2 READ foreColor2 WRITE setForeColor2)
    Q_PROPERTY(QColor foreColor3 READ foreColor3 WRITE setForeColor3)
    Q_PROPERTY(QColor foreColor4 READ foreColor4 WRITE setForeColor4)
    Q_PROPERTY(QColor foreColor5 READ foreColor5 WRITE setForeColor5)
    Q_PROPERTY(QColor disabledBackgroundColor1 READ disabledBackgroundColor1 WRITE setDisabledBackgroundColor1)
    Q_PROPERTY(QColor disabledBackgroundColor2 READ disabledBackgroundColor2 WRITE setDisabledBackgroundColor2)
    Q_PROPERTY(QColor disabledBackgroundColor3 READ disabledBackgroundColor3 WRITE setDisabledBackgroundColor3)
    Q_PROPERTY(QColor disabledBackgroundColor4 READ disabledBackgroundColor4 WRITE setDisabledBackgroundColor4)
    Q_PROPERTY(QColor disabledBackgroundColor5 READ disabledBackgroundColor5 WRITE setDisabledBackgroundColor5)
    Q_PROPERTY(QColor disabledColor1 READ disabledColor1 WRITE setDisabledColor1)
    Q_PROPERTY(QColor disabledColor2 READ disabledColor2 WRITE setDisabledColor2)
    Q_PROPERTY(QColor disabledColor3 READ disabledColor3 WRITE setDisabledColor3)
    Q_PROPERTY(QColor disabledColor4 READ disabledColor4 WRITE setDisabledColor4)
    Q_PROPERTY(QColor disabledColor5 READ disabledColor5 WRITE setDisabledColor5)

public:
    enum ModeType
    {
        Mode1 = 0,
        Mode2,
        Mode3,
        Mode4,
        Mode5
    };

public:
    explicit ColorButton(QWidget *parent = 0);

public:
    QColor backgroundColor1() const;
    QColor backgroundColor2() const;
    QColor backgroundColor3() const;
    QColor backgroundColor4() const;
    QColor backgroundColor5() const;
    QColor foreColor1() const;
    QColor foreColor2() const;
    QColor foreColor3() const;
    QColor foreColor4() const;
    QColor foreColor5() const;
    QColor disabledBackgroundColor1() const;
    QColor disabledBackgroundColor2() const;
    QColor disabledBackgroundColor3() const;
    QColor disabledBackgroundColor4() const;
    QColor disabledBackgroundColor5() const;
    QColor disabledColor1() const;
    QColor disabledColor2() const;
    QColor disabledColor3() const;
    QColor disabledColor4() const;
    QColor disabledColor5() const;
    void setBackgroundColor1(const QColor& color);
    void setBackgroundColor2(const QColor& color);
    void setBackgroundColor3(const QColor& color);
    void setBackgroundColor4(const QColor& color);
    void setBackgroundColor5(const QColor& color);
    void setForeColor1(const QColor& color);
    void setForeColor2(const QColor& color);
    void setForeColor3(const QColor& color);
    void setForeColor4(const QColor& color);
    void setForeColor5(const QColor& color);
    void setDisabledColor1(const QColor& color);
    void setDisabledColor2(const QColor& color);
    void setDisabledColor3(const QColor& color);
    void setDisabledColor4(const QColor& color);
    void setDisabledColor5(const QColor& color);
    void setDisabledBackgroundColor1(const QColor& color);
    void setDisabledBackgroundColor2(const QColor& color);
    void setDisabledBackgroundColor3(const QColor& color);
    void setDisabledBackgroundColor4(const QColor& color);
    void setDisabledBackgroundColor5(const QColor& color);

    ModeType mode() const;
    void setMode( ModeType mode );

signals:

private slots:

protected:
    void showEvent(QShowEvent *);

private:
    void updateStyleSheet(int index);

private:
    struct ColorButtonData
    {
        QColor  normal;
        QColor  hover;
        QColor  pressed;
        QColor  disable;
    };
    ColorButtonData     m_color[5];
    ColorButtonData     m_bg_color[5];
    QString             m_style[5];
    ModeType            m_mode;
};

#endif // COLORBUTTON_H
