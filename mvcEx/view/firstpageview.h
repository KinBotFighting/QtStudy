#ifndef FIRSTPAGEVIEW_H
#define FIRSTPAGEVIEW_H

#include <QWidget>
#include <QVBoxLayout>

class FirstPageView : public QWidget
{
    Q_OBJECT
public:
    explicit FirstPageView(QWidget *parent = nullptr);

private:
    void setUi();
    QVBoxLayout *mainLayout;



signals:

public slots:
    void showUiSlot();
    void showFinishedCountResultUiSlot();

};

#endif // FIRSTPAGEVIEW_H
