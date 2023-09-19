#ifndef SEMINAR7_CHATWINDOW_H
#define SEMINAR7_CHATWINDOW_H

#include <QWidget>
#include "ChatSession.h"
#include "Observer.h"


QT_BEGIN_NAMESPACE
namespace Ui { class ChatWindow; }
QT_END_NAMESPACE

class ChatWindow : public QWidget , public Observer {
Q_OBJECT

public:
    explicit ChatWindow(ChatSession &cs, QWidget *parent = nullptr);

    ~ChatWindow() override;

private:
    Ui::ChatWindow *ui;
    ChatSession &chatSession;
public:
    void update() override;
    void sendMessage();
    void populate_list();
    void connect_signals_and_slots();
};


#endif //SEMINAR7_CHATWINDOW_H
