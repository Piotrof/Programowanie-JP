#ifndef RNG_H
#define RNG_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class RNG; }
QT_END_NAMESPACE

class RNG : public QMainWindow
{
    Q_OBJECT

public:
    RNG(QWidget *parent = nullptr);
    ~RNG();

private:
    Ui::RNG *ui;

private slots:
    void ButtonPushed();
};
#endif // RNG_H
