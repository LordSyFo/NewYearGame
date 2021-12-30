#pragma once

#include <QtWidgets/QWidget>
#include <QtWidgets/QtWidgets>

#include <functional>
#include <vector>

#include <memory>

namespace NEG {

typedef std::function<void(const QString&)> OnGuessCallback_t;

class TextGuessWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TextGuessWidget(QWidget *parent = 0); //Constructor
    virtual ~TextGuessWidget(); // Destructor

    void SetQuestionText(const QString &question);

    void AddOnGuessCallback(OnGuessCallback_t func);

private slots:
    void HandleBtnPress();

private:
   std::unique_ptr<QLabel> text_label_;
   std::unique_ptr<QLineEdit> line_edit_;
   std::unique_ptr<QPushButton> push_btn_;

   std::unique_ptr<QGridLayout> layout_;

   std::vector<OnGuessCallback_t> on_guess_callbacks_;
};

}