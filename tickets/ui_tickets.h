/********************************************************************************
** Form generated from reading UI file 'tickets.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TICKETS_H
#define UI_TICKETS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ticketsClass
{
public:
    QAction *buy;
    QAction *refund;
    QAction *FAQ;
    QAction *ask;
    QAction *personal;
    QAction *settings;
    QAction *schedule;
    QAction *QuitMain;
    QAction *QuitAction;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout;
    QStackedWidget *stackedWidget;
    QWidget *buyPage;
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLabel *label_8;
    QDateEdit *dateEdit_4;
    QCheckBox *checkBox;
    QPushButton *pushButton_3;
    QWidget *refundPage;
    QVBoxLayout *verticalLayout_9;
    QWidget *widget_2;
    QPushButton *pushButton_4;
    QWidget *verticalLayoutWidget_5;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_9;
    QLineEdit *lineEdit_6;
    QWidget *schedulePage;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_10;
    QCalendarWidget *calendarWidget_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_2;
    QWidget *horizontalLayoutWidget_10;
    QHBoxLayout *horizontalLayout_24;
    QLabel *label_71;
    QDateEdit *dateEdit_46;
    QLabel *label_72;
    QDateEdit *dateEdit_47;
    QLabel *label_73;
    QWidget *horizontalLayoutWidget_11;
    QHBoxLayout *horizontalLayout_25;
    QLabel *label_74;
    QDateEdit *dateEdit_48;
    QLabel *label_75;
    QDateEdit *dateEdit_49;
    QLabel *label_76;
    QWidget *horizontalLayoutWidget_12;
    QHBoxLayout *horizontalLayout_26;
    QLabel *label_77;
    QDateEdit *dateEdit_50;
    QLabel *label_78;
    QDateEdit *dateEdit_51;
    QLabel *label_79;
    QWidget *horizontalLayoutWidget_14;
    QHBoxLayout *horizontalLayout_28;
    QLabel *label_83;
    QDateEdit *dateEdit_54;
    QLabel *label_84;
    QDateEdit *dateEdit_55;
    QLabel *label_85;
    QWidget *horizontalLayoutWidget_15;
    QHBoxLayout *horizontalLayout_29;
    QLabel *label_86;
    QDateEdit *dateEdit_56;
    QLabel *label_87;
    QDateEdit *dateEdit_57;
    QLabel *label_88;
    QWidget *FAQPage;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QLabel *label_2;
    QWidget *mainPage;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout;
    QLabel *label_11;
    QPushButton *buyPageBtn;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *MenuQuit;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ticketsClass)
    {
        if (ticketsClass->objectName().isEmpty())
            ticketsClass->setObjectName(QString::fromUtf8("ticketsClass"));
        ticketsClass->setWindowModality(Qt::NonModal);
        ticketsClass->resize(640, 480);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ticketsClass->sizePolicy().hasHeightForWidth());
        ticketsClass->setSizePolicy(sizePolicy);
        buy = new QAction(ticketsClass);
        buy->setObjectName(QString::fromUtf8("buy"));
        refund = new QAction(ticketsClass);
        refund->setObjectName(QString::fromUtf8("refund"));
        FAQ = new QAction(ticketsClass);
        FAQ->setObjectName(QString::fromUtf8("FAQ"));
        ask = new QAction(ticketsClass);
        ask->setObjectName(QString::fromUtf8("ask"));
        personal = new QAction(ticketsClass);
        personal->setObjectName(QString::fromUtf8("personal"));
        settings = new QAction(ticketsClass);
        settings->setObjectName(QString::fromUtf8("settings"));
        schedule = new QAction(ticketsClass);
        schedule->setObjectName(QString::fromUtf8("schedule"));
        QuitMain = new QAction(ticketsClass);
        QuitMain->setObjectName(QString::fromUtf8("QuitMain"));
        QuitAction = new QAction(ticketsClass);
        QuitAction->setObjectName(QString::fromUtf8("QuitAction"));
        centralWidget = new QWidget(ticketsClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        verticalLayout_6 = new QVBoxLayout(centralWidget);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        sizePolicy.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy);
        stackedWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(194, 255, 255);"));
        stackedWidget->setFrameShape(QFrame::NoFrame);
        buyPage = new QWidget();
        buyPage->setObjectName(QString::fromUtf8("buyPage"));
        verticalLayout_7 = new QVBoxLayout(buyPage);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        lineEdit_4 = new QLineEdit(buyPage);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit_4->sizePolicy().hasHeightForWidth());
        lineEdit_4->setSizePolicy(sizePolicy1);
        lineEdit_4->setStyleSheet(QString::fromUtf8("border-style: solid; border-width: 2px; border-color: green;"));

        horizontalLayout_3->addWidget(lineEdit_4);

        lineEdit_5 = new QLineEdit(buyPage);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        sizePolicy1.setHeightForWidth(lineEdit_5->sizePolicy().hasHeightForWidth());
        lineEdit_5->setSizePolicy(sizePolicy1);
        lineEdit_5->setStyleSheet(QString::fromUtf8("border-style: solid; border-width: 2px; border-color: green;"));

        horizontalLayout_3->addWidget(lineEdit_5);

        label_8 = new QLabel(buyPage);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_3->addWidget(label_8);

        dateEdit_4 = new QDateEdit(buyPage);
        dateEdit_4->setObjectName(QString::fromUtf8("dateEdit_4"));
        dateEdit_4->setStyleSheet(QString::fromUtf8("border-style: solid; border-width: 2px; border-color: green;"));

        horizontalLayout_3->addWidget(dateEdit_4);


        verticalLayout_2->addLayout(horizontalLayout_3);

        checkBox = new QCheckBox(buyPage);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setLayoutDirection(Qt::LeftToRight);
        checkBox->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_2->addWidget(checkBox);

        pushButton_3 = new QPushButton(buyPage);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy2);
        pushButton_3->setStyleSheet(QString::fromUtf8("font: 12pt; border-style: solid; border-width: 1px; border-color: green;"));

        verticalLayout_2->addWidget(pushButton_3);


        verticalLayout_7->addLayout(verticalLayout_2);

        stackedWidget->addWidget(buyPage);
        refundPage = new QWidget();
        refundPage->setObjectName(QString::fromUtf8("refundPage"));
        verticalLayout_9 = new QVBoxLayout(refundPage);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        widget_2 = new QWidget(refundPage);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy3);
        widget_2->setMaximumSize(QSize(6000, 200));
        widget_2->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 244, 255); border-style: solid; border-width: 1px; border-color: green;"));
        pushButton_4 = new QPushButton(widget_2);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(300, 30, 271, 71));
        pushButton_4->setStyleSheet(QString::fromUtf8("font: 16pt;"));
        verticalLayoutWidget_5 = new QWidget(widget_2);
        verticalLayoutWidget_5->setObjectName(QString::fromUtf8("verticalLayoutWidget_5"));
        verticalLayoutWidget_5->setGeometry(QRect(0, 30, 291, 71));
        verticalLayout_5 = new QVBoxLayout(verticalLayoutWidget_5);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(verticalLayoutWidget_5);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy4);

        verticalLayout_5->addWidget(label_9);

        lineEdit_6 = new QLineEdit(verticalLayoutWidget_5);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));

        verticalLayout_5->addWidget(lineEdit_6);


        verticalLayout_9->addWidget(widget_2);

        stackedWidget->addWidget(refundPage);
        schedulePage = new QWidget();
        schedulePage->setObjectName(QString::fromUtf8("schedulePage"));
        verticalLayout_8 = new QVBoxLayout(schedulePage);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        label_10 = new QLabel(schedulePage);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setStyleSheet(QString::fromUtf8("font: 16pt;"));
        label_10->setAlignment(Qt::AlignCenter);
        label_10->setWordWrap(true);

        verticalLayout_8->addWidget(label_10);

        calendarWidget_2 = new QCalendarWidget(schedulePage);
        calendarWidget_2->setObjectName(QString::fromUtf8("calendarWidget_2"));
        calendarWidget_2->setStyleSheet(QString::fromUtf8("color: black;"));

        verticalLayout_8->addWidget(calendarWidget_2);

        scrollArea = new QScrollArea(schedulePage);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setStyleSheet(QString::fromUtf8("border-style: dotted; border-width:1px; border-color: blue;"));
        scrollArea->setWidgetResizable(false);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 600, 164));
        horizontalLayoutWidget_10 = new QWidget(scrollAreaWidgetContents_2);
        horizontalLayoutWidget_10->setObjectName(QString::fromUtf8("horizontalLayoutWidget_10"));
        horizontalLayoutWidget_10->setGeometry(QRect(10, 50, 581, 31));
        horizontalLayout_24 = new QHBoxLayout(horizontalLayoutWidget_10);
        horizontalLayout_24->setSpacing(6);
        horizontalLayout_24->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_24->setObjectName(QString::fromUtf8("horizontalLayout_24"));
        horizontalLayout_24->setContentsMargins(0, 0, 0, 0);
        label_71 = new QLabel(horizontalLayoutWidget_10);
        label_71->setObjectName(QString::fromUtf8("label_71"));

        horizontalLayout_24->addWidget(label_71);

        dateEdit_46 = new QDateEdit(horizontalLayoutWidget_10);
        dateEdit_46->setObjectName(QString::fromUtf8("dateEdit_46"));
        dateEdit_46->setReadOnly(true);

        horizontalLayout_24->addWidget(dateEdit_46);

        label_72 = new QLabel(horizontalLayoutWidget_10);
        label_72->setObjectName(QString::fromUtf8("label_72"));

        horizontalLayout_24->addWidget(label_72);

        dateEdit_47 = new QDateEdit(horizontalLayoutWidget_10);
        dateEdit_47->setObjectName(QString::fromUtf8("dateEdit_47"));
        sizePolicy2.setHeightForWidth(dateEdit_47->sizePolicy().hasHeightForWidth());
        dateEdit_47->setSizePolicy(sizePolicy2);
        dateEdit_47->setReadOnly(true);

        horizontalLayout_24->addWidget(dateEdit_47);

        label_73 = new QLabel(horizontalLayoutWidget_10);
        label_73->setObjectName(QString::fromUtf8("label_73"));
        sizePolicy3.setHeightForWidth(label_73->sizePolicy().hasHeightForWidth());
        label_73->setSizePolicy(sizePolicy3);

        horizontalLayout_24->addWidget(label_73);

        horizontalLayoutWidget_11 = new QWidget(scrollAreaWidgetContents_2);
        horizontalLayoutWidget_11->setObjectName(QString::fromUtf8("horizontalLayoutWidget_11"));
        horizontalLayoutWidget_11->setGeometry(QRect(10, 10, 581, 31));
        horizontalLayout_25 = new QHBoxLayout(horizontalLayoutWidget_11);
        horizontalLayout_25->setSpacing(6);
        horizontalLayout_25->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_25->setObjectName(QString::fromUtf8("horizontalLayout_25"));
        horizontalLayout_25->setContentsMargins(0, 0, 0, 0);
        label_74 = new QLabel(horizontalLayoutWidget_11);
        label_74->setObjectName(QString::fromUtf8("label_74"));

        horizontalLayout_25->addWidget(label_74);

        dateEdit_48 = new QDateEdit(horizontalLayoutWidget_11);
        dateEdit_48->setObjectName(QString::fromUtf8("dateEdit_48"));
        dateEdit_48->setReadOnly(true);

        horizontalLayout_25->addWidget(dateEdit_48);

        label_75 = new QLabel(horizontalLayoutWidget_11);
        label_75->setObjectName(QString::fromUtf8("label_75"));

        horizontalLayout_25->addWidget(label_75);

        dateEdit_49 = new QDateEdit(horizontalLayoutWidget_11);
        dateEdit_49->setObjectName(QString::fromUtf8("dateEdit_49"));
        sizePolicy2.setHeightForWidth(dateEdit_49->sizePolicy().hasHeightForWidth());
        dateEdit_49->setSizePolicy(sizePolicy2);
        dateEdit_49->setReadOnly(true);

        horizontalLayout_25->addWidget(dateEdit_49);

        label_76 = new QLabel(horizontalLayoutWidget_11);
        label_76->setObjectName(QString::fromUtf8("label_76"));
        sizePolicy3.setHeightForWidth(label_76->sizePolicy().hasHeightForWidth());
        label_76->setSizePolicy(sizePolicy3);

        horizontalLayout_25->addWidget(label_76);

        horizontalLayoutWidget_12 = new QWidget(scrollAreaWidgetContents_2);
        horizontalLayoutWidget_12->setObjectName(QString::fromUtf8("horizontalLayoutWidget_12"));
        horizontalLayoutWidget_12->setGeometry(QRect(10, 90, 581, 31));
        horizontalLayout_26 = new QHBoxLayout(horizontalLayoutWidget_12);
        horizontalLayout_26->setSpacing(6);
        horizontalLayout_26->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_26->setObjectName(QString::fromUtf8("horizontalLayout_26"));
        horizontalLayout_26->setContentsMargins(0, 0, 0, 0);
        label_77 = new QLabel(horizontalLayoutWidget_12);
        label_77->setObjectName(QString::fromUtf8("label_77"));

        horizontalLayout_26->addWidget(label_77);

        dateEdit_50 = new QDateEdit(horizontalLayoutWidget_12);
        dateEdit_50->setObjectName(QString::fromUtf8("dateEdit_50"));
        dateEdit_50->setReadOnly(true);

        horizontalLayout_26->addWidget(dateEdit_50);

        label_78 = new QLabel(horizontalLayoutWidget_12);
        label_78->setObjectName(QString::fromUtf8("label_78"));

        horizontalLayout_26->addWidget(label_78);

        dateEdit_51 = new QDateEdit(horizontalLayoutWidget_12);
        dateEdit_51->setObjectName(QString::fromUtf8("dateEdit_51"));
        sizePolicy2.setHeightForWidth(dateEdit_51->sizePolicy().hasHeightForWidth());
        dateEdit_51->setSizePolicy(sizePolicy2);
        dateEdit_51->setReadOnly(true);

        horizontalLayout_26->addWidget(dateEdit_51);

        label_79 = new QLabel(horizontalLayoutWidget_12);
        label_79->setObjectName(QString::fromUtf8("label_79"));
        sizePolicy3.setHeightForWidth(label_79->sizePolicy().hasHeightForWidth());
        label_79->setSizePolicy(sizePolicy3);

        horizontalLayout_26->addWidget(label_79);

        horizontalLayoutWidget_14 = new QWidget(scrollAreaWidgetContents_2);
        horizontalLayoutWidget_14->setObjectName(QString::fromUtf8("horizontalLayoutWidget_14"));
        horizontalLayoutWidget_14->setGeometry(QRect(10, 120, 581, 31));
        horizontalLayout_28 = new QHBoxLayout(horizontalLayoutWidget_14);
        horizontalLayout_28->setSpacing(6);
        horizontalLayout_28->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_28->setObjectName(QString::fromUtf8("horizontalLayout_28"));
        horizontalLayout_28->setContentsMargins(0, 0, 0, 0);
        label_83 = new QLabel(horizontalLayoutWidget_14);
        label_83->setObjectName(QString::fromUtf8("label_83"));

        horizontalLayout_28->addWidget(label_83);

        dateEdit_54 = new QDateEdit(horizontalLayoutWidget_14);
        dateEdit_54->setObjectName(QString::fromUtf8("dateEdit_54"));
        dateEdit_54->setReadOnly(true);

        horizontalLayout_28->addWidget(dateEdit_54);

        label_84 = new QLabel(horizontalLayoutWidget_14);
        label_84->setObjectName(QString::fromUtf8("label_84"));

        horizontalLayout_28->addWidget(label_84);

        dateEdit_55 = new QDateEdit(horizontalLayoutWidget_14);
        dateEdit_55->setObjectName(QString::fromUtf8("dateEdit_55"));
        sizePolicy2.setHeightForWidth(dateEdit_55->sizePolicy().hasHeightForWidth());
        dateEdit_55->setSizePolicy(sizePolicy2);
        dateEdit_55->setReadOnly(true);

        horizontalLayout_28->addWidget(dateEdit_55);

        label_85 = new QLabel(horizontalLayoutWidget_14);
        label_85->setObjectName(QString::fromUtf8("label_85"));
        sizePolicy3.setHeightForWidth(label_85->sizePolicy().hasHeightForWidth());
        label_85->setSizePolicy(sizePolicy3);

        horizontalLayout_28->addWidget(label_85);

        horizontalLayoutWidget_15 = new QWidget(scrollAreaWidgetContents_2);
        horizontalLayoutWidget_15->setObjectName(QString::fromUtf8("horizontalLayoutWidget_15"));
        horizontalLayoutWidget_15->setGeometry(QRect(10, 200, 581, 31));
        horizontalLayout_29 = new QHBoxLayout(horizontalLayoutWidget_15);
        horizontalLayout_29->setSpacing(6);
        horizontalLayout_29->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_29->setObjectName(QString::fromUtf8("horizontalLayout_29"));
        horizontalLayout_29->setContentsMargins(0, 0, 0, 0);
        label_86 = new QLabel(horizontalLayoutWidget_15);
        label_86->setObjectName(QString::fromUtf8("label_86"));

        horizontalLayout_29->addWidget(label_86);

        dateEdit_56 = new QDateEdit(horizontalLayoutWidget_15);
        dateEdit_56->setObjectName(QString::fromUtf8("dateEdit_56"));
        dateEdit_56->setReadOnly(true);

        horizontalLayout_29->addWidget(dateEdit_56);

        label_87 = new QLabel(horizontalLayoutWidget_15);
        label_87->setObjectName(QString::fromUtf8("label_87"));

        horizontalLayout_29->addWidget(label_87);

        dateEdit_57 = new QDateEdit(horizontalLayoutWidget_15);
        dateEdit_57->setObjectName(QString::fromUtf8("dateEdit_57"));
        sizePolicy2.setHeightForWidth(dateEdit_57->sizePolicy().hasHeightForWidth());
        dateEdit_57->setSizePolicy(sizePolicy2);
        dateEdit_57->setReadOnly(true);

        horizontalLayout_29->addWidget(dateEdit_57);

        label_88 = new QLabel(horizontalLayoutWidget_15);
        label_88->setObjectName(QString::fromUtf8("label_88"));
        sizePolicy3.setHeightForWidth(label_88->sizePolicy().hasHeightForWidth());
        label_88->setSizePolicy(sizePolicy3);

        horizontalLayout_29->addWidget(label_88);

        scrollArea->setWidget(scrollAreaWidgetContents_2);

        verticalLayout_8->addWidget(scrollArea);

        stackedWidget->addWidget(schedulePage);
        FAQPage = new QWidget();
        FAQPage->setObjectName(QString::fromUtf8("FAQPage"));
        verticalLayout_3 = new QVBoxLayout(FAQPage);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label = new QLabel(FAQPage);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_3->addWidget(label);

        label_2 = new QLabel(FAQPage);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        verticalLayout_3->addWidget(label_2);

        stackedWidget->addWidget(FAQPage);
        mainPage = new QWidget();
        mainPage->setObjectName(QString::fromUtf8("mainPage"));
        verticalLayout_4 = new QVBoxLayout(mainPage);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_11 = new QLabel(mainPage);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        sizePolicy.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy);
        label_11->setStyleSheet(QString::fromUtf8("background-color: white; border-style: solid; border-width: 1px; border-color: green;"));
        label_11->setAlignment(Qt::AlignCenter);
        label_11->setWordWrap(true);

        verticalLayout->addWidget(label_11);

        buyPageBtn = new QPushButton(mainPage);
        buyPageBtn->setObjectName(QString::fromUtf8("buyPageBtn"));
        buyPageBtn->setEnabled(true);
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(buyPageBtn->sizePolicy().hasHeightForWidth());
        buyPageBtn->setSizePolicy(sizePolicy5);
        buyPageBtn->setMaximumSize(QSize(6000, 90));
        buyPageBtn->setSizeIncrement(QSize(0, 0));
        buyPageBtn->setStyleSheet(QString::fromUtf8("background-color: white; font: 12pt; border-style: solid; border-width: 1px; border-color: green;"));

        verticalLayout->addWidget(buyPageBtn);


        verticalLayout_4->addLayout(verticalLayout);

        stackedWidget->addWidget(mainPage);

        horizontalLayout->addWidget(stackedWidget);


        verticalLayout_6->addLayout(horizontalLayout);

        ticketsClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ticketsClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 640, 21));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        menu_3 = new QMenu(menuBar);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        MenuQuit = new QMenu(menuBar);
        MenuQuit->setObjectName(QString::fromUtf8("MenuQuit"));
        ticketsClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ticketsClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        ticketsClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ticketsClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        ticketsClass->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_3->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(MenuQuit->menuAction());
        menu->addAction(buy);
        menu->addAction(refund);
        menu->addAction(schedule);
        menu_2->addAction(FAQ);
        menu_2->addAction(ask);
        menu_3->addAction(personal);
        menu_3->addAction(settings);
        MenuQuit->addAction(QuitMain);
        MenuQuit->addAction(QuitAction);

        retranslateUi(ticketsClass);

        stackedWidget->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(ticketsClass);
    } // setupUi

    void retranslateUi(QMainWindow *ticketsClass)
    {
        ticketsClass->setWindowTitle(QCoreApplication::translate("ticketsClass", "tickets", nullptr));
        buy->setText(QCoreApplication::translate("ticketsClass", "\320\232\321\203\320\277\320\270\321\202\321\214", nullptr));
        refund->setText(QCoreApplication::translate("ticketsClass", "\320\222\320\276\320\267\320\262\321\200\320\260\321\202", nullptr));
        FAQ->setText(QCoreApplication::translate("ticketsClass", "FAQ", nullptr));
        ask->setText(QCoreApplication::translate("ticketsClass", "\320\227\320\260\320\264\320\260\321\202\321\214 \320\262\320\276\320\277\321\200\320\276\321\201", nullptr));
        personal->setText(QCoreApplication::translate("ticketsClass", "\320\233\320\270\321\207\320\275\321\213\320\265 \320\264\320\260\320\275\320\275\321\213\320\265", nullptr));
        settings->setText(QCoreApplication::translate("ticketsClass", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \320\277\321\200\320\270\320\273\320\276\320\266\320\265\320\275\320\270\321\217", nullptr));
        schedule->setText(QCoreApplication::translate("ticketsClass", "\320\240\320\260\321\201\320\277\320\270\321\201\320\260\320\275\320\270\320\265", nullptr));
        QuitMain->setText(QCoreApplication::translate("ticketsClass", "\320\235\320\260 \320\263\320\273\320\260\320\262\320\275\321\203\321\216 \321\201\321\202\321\200\320\260\320\275\320\270\321\206\321\203", nullptr));
        QuitAction->setText(QCoreApplication::translate("ticketsClass", "\320\222\321\213\320\271\321\202\320\270 \320\270\320\267 \320\277\321\200\320\270\320\273\320\276\320\266\320\265\320\275\320\270\321\217", nullptr));
        lineEdit_4->setText(QString());
        lineEdit_4->setPlaceholderText(QCoreApplication::translate("ticketsClass", "\320\236\321\202\320\272\321\203\320\264\320\260", nullptr));
        lineEdit_5->setText(QString());
        lineEdit_5->setPlaceholderText(QCoreApplication::translate("ticketsClass", "\320\232\321\203\320\264\320\260", nullptr));
        label_8->setText(QCoreApplication::translate("ticketsClass", "\320\232\320\276\320\263\320\264\320\260", nullptr));
        checkBox->setText(QCoreApplication::translate("ticketsClass", "\320\230\321\201\320\272\320\260\321\202\321\214 \320\274\320\260\321\200\321\210\321\200\321\203\321\202\321\213 \321\201 \320\277\320\265\321\200\320\265\321\201\320\260\320\264\320\272\320\276\320\271", nullptr));
        pushButton_3->setText(QCoreApplication::translate("ticketsClass", "\320\235\320\260\320\271\321\202\320\270 \320\261\320\270\320\273\320\265\321\202\321\213", nullptr));
        pushButton_4->setText(QCoreApplication::translate("ticketsClass", "\320\236\321\204\320\276\321\200\320\274\320\270\321\202\321\214 \320\262\320\276\320\267\320\262\321\200\320\260\321\202", nullptr));
        label_9->setText(QCoreApplication::translate("ticketsClass", "\320\243\320\272\320\260\320\266\320\270\321\202\320\265 \321\203\320\275\320\270\320\272\320\260\320\273\321\214\320\275\321\213\320\271 \320\275\320\276\320\274\320\265\321\200 \320\261\320\270\320\273\320\265\321\202\320\260:", nullptr));
        lineEdit_6->setPlaceholderText(QCoreApplication::translate("ticketsClass", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 ID", nullptr));
        label_10->setText(QCoreApplication::translate("ticketsClass", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\264\320\260\321\202\321\203:", nullptr));
        label_71->setText(QCoreApplication::translate("ticketsClass", "\320\224\320\260\321\202\320\260 \320\276\321\202\320\261\321\213\321\202\320\270\321\217", nullptr));
        label_72->setText(QCoreApplication::translate("ticketsClass", "\320\224\320\260\321\202\320\260 \320\277\321\200\320\270\320\261\321\213\321\202\320\270\321\217", nullptr));
        label_73->setText(QCoreApplication::translate("ticketsClass", "\320\234\320\265\321\201\321\202\320\276 \320\276\321\202\320\261\321\213\321\202\320\270\321\217-\320\274\320\265\321\201\321\202\320\276 \320\277\321\200\320\270\320\261\321\213\321\202\320\270\321\217; \320\240\320\265\320\271\321\201 \342\204\226", nullptr));
        label_74->setText(QCoreApplication::translate("ticketsClass", "\320\224\320\260\321\202\320\260 \320\276\321\202\320\261\321\213\321\202\320\270\321\217", nullptr));
        label_75->setText(QCoreApplication::translate("ticketsClass", "\320\224\320\260\321\202\320\260 \320\277\321\200\320\270\320\261\321\213\321\202\320\270\321\217", nullptr));
        label_76->setText(QCoreApplication::translate("ticketsClass", "\320\234\320\265\321\201\321\202\320\276 \320\276\321\202\320\261\321\213\321\202\320\270\321\217-\320\274\320\265\321\201\321\202\320\276 \320\277\321\200\320\270\320\261\321\213\321\202\320\270\321\217; \320\240\320\265\320\271\321\201 \342\204\226", nullptr));
        label_77->setText(QCoreApplication::translate("ticketsClass", "\320\224\320\260\321\202\320\260 \320\276\321\202\320\261\321\213\321\202\320\270\321\217", nullptr));
        label_78->setText(QCoreApplication::translate("ticketsClass", "\320\224\320\260\321\202\320\260 \320\277\321\200\320\270\320\261\321\213\321\202\320\270\321\217", nullptr));
        label_79->setText(QCoreApplication::translate("ticketsClass", "\320\234\320\265\321\201\321\202\320\276 \320\276\321\202\320\261\321\213\321\202\320\270\321\217-\320\274\320\265\321\201\321\202\320\276 \320\277\321\200\320\270\320\261\321\213\321\202\320\270\321\217; \320\240\320\265\320\271\321\201 \342\204\226", nullptr));
        label_83->setText(QCoreApplication::translate("ticketsClass", "\320\224\320\260\321\202\320\260 \320\276\321\202\320\261\321\213\321\202\320\270\321\217", nullptr));
        label_84->setText(QCoreApplication::translate("ticketsClass", "\320\224\320\260\321\202\320\260 \320\277\321\200\320\270\320\261\321\213\321\202\320\270\321\217", nullptr));
        label_85->setText(QCoreApplication::translate("ticketsClass", "\320\234\320\265\321\201\321\202\320\276 \320\276\321\202\320\261\321\213\321\202\320\270\321\217-\320\274\320\265\321\201\321\202\320\276 \320\277\321\200\320\270\320\261\321\213\321\202\320\270\321\217; \320\240\320\265\320\271\321\201 \342\204\226", nullptr));
        label_86->setText(QCoreApplication::translate("ticketsClass", "\320\224\320\260\321\202\320\260 \320\276\321\202\320\261\321\213\321\202\320\270\321\217", nullptr));
        label_87->setText(QCoreApplication::translate("ticketsClass", "\320\224\320\260\321\202\320\260 \320\277\321\200\320\270\320\261\321\213\321\202\320\270\321\217", nullptr));
        label_88->setText(QCoreApplication::translate("ticketsClass", "\320\234\320\265\321\201\321\202\320\276 \320\276\321\202\320\261\321\213\321\202\320\270\321\217-\320\274\320\265\321\201\321\202\320\276 \320\277\321\200\320\270\320\261\321\213\321\202\320\270\321\217; \320\240\320\265\320\271\321\201 \342\204\226", nullptr));
        label->setText(QCoreApplication::translate("ticketsClass", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt;\">\320\247\320\260\321\201\321\202\320\276 \320\267\320\260\320\264\320\260\320\262\320\260\320\265\320\274\321\213\320\265 \320\262\320\276\320\277\321\200\320\276\321\201\321\213 \320\277\320\276 \320\277\321\200\320\270\320\273\320\276\320\266\320\265\320\275\320\270\321\216:</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("ticketsClass", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">\320\222\320\276\320\277\321\200\320\276\321\201\321\213 \320\270 \320\276\321\202\320\262\320\265\321\202\321\213</span></p></body></html>", nullptr));
        label_11->setText(QCoreApplication::translate("ticketsClass", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt;\">\320\224\320\276\320\261\321\200\320\276 \320\277\320\276\320\266\320\260\320\273\320\276\320\262\320\260\321\202\321\214 \320\262 \320\275\320\260\321\210\320\265 \320\277\321\200\320\270\320\273\320\276\320\266\320\265\320\275\320\270\320\265 \320\264\320\273\321\217 \320\277\320\276\320\272\321\203\320\277\320\272\320\270 \320\261\320\270\320\273\320\265\321\202\320\276\320\262 \320\275\320\260 \320\277\320\276\320\265\320\267\320\264!</span></p><p align=\"center\"><span style=\" font-size:18pt;\">\320\222\321\213 \320\274\320\276\320\266\320\265\321\202\320\265 \320\272\321\203\320\277\320\270\321\202\321\214 \320\261\320\270\320\273\320\265\321\202\321\213 \320\270 \320\277\320\276\321\201\320\274\320\276\321\202\321\200\320\265\321\202\321\214 \321\200\320\260\321\201\320\277\320\270\321\201\320\260\320\275\320\270\320\265, \320\260 \321\202\320\260\320\272\320\266\320\265 \320\276\321\204\320\276\321\200\320\274\320\270\321\202\321\214"
                        " \320\262\320\276\320\267\320\262\321\200\320\260\321\202 \320\261\320\270\320\273\320\265\321\202\320\260!</span></p></body></html>", nullptr));
        buyPageBtn->setText(QCoreApplication::translate("ticketsClass", "\320\232\321\203\320\277\320\270\321\202\321\214 \320\261\320\270\320\273\320\265\321\202\321\213", nullptr));
        menu->setTitle(QCoreApplication::translate("ticketsClass", "\320\221\320\270\320\273\320\265\321\202\321\213", nullptr));
        menu_2->setTitle(QCoreApplication::translate("ticketsClass", "\320\237\320\276\320\274\320\276\321\211\321\214", nullptr));
        menu_3->setTitle(QCoreApplication::translate("ticketsClass", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", nullptr));
        MenuQuit->setTitle(QCoreApplication::translate("ticketsClass", "\320\222\321\213\321\205\320\276\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ticketsClass: public Ui_ticketsClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TICKETS_H
