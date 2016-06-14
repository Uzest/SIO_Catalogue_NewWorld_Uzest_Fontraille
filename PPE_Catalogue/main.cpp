/**
 * @author A Fontraille
 * @date 11 septembre 2015
 * @file main.cpp
 */
#include <QApplication>
#include "pdf.h"

/**
 * @brief main
 * @param argc
 * @param argv
 * @return
 */

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Pdf pdf;
    pdf.start();

    return 0;
}
