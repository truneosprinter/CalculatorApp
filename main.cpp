#include "calculatorapp.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();

    // Attempt to load translations for available languages
    for (const QString &locale : uiLanguages) {
        const QString baseName = "Calculator_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            qDebug() << "Translation loaded for language:" << locale;
            break;
        } else {
            qWarning() << "Translation not available for language:" << locale;
        }
    }

    CalculatorApp w;
    w.show();

    return a.exec();
}
