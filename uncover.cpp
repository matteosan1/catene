#include "uncover.h"

#include <QFile>
#include <QTextStream>
#include <QDebug>

#include <algorithm>
#include <random>
#include <chrono>

#define MAX_PUNTI   7

Uncover::Uncover(const QString& filename, QObject* parent) :
    QObject(parent),
    m_turni(0),
    m_punti(MAX_PUNTI)
{
    for (int i=0; i<4; i++)
        m_suggerimenti.append(0);

    QFile file(filename);
    if (file.open(QIODevice::ReadOnly)) {
        QTextStream stream(&file);

        while (!stream.atEnd()) {
            QString line = stream.readLine();
            if (line == "")
                continue;
            //qDebug() << line;

            QStringList c = line.split(",");
            QList<QString> catena;
            foreach(QString s, c)
                catena.append(s);
            m_catene.append(catena);
        }

        file.close();
        change();
    }
}

QVariantList Uncover::catena() const
{
    return m_catena;
}

void Uncover::suggerimento(const int i)
{
    if (m_suggerimenti[i] == 4)
        return;

    m_suggerimenti[i]++;
    m_punti--;

    updateCatena();
}

void Uncover::mostraTutto()
{
    QList<QString> aCatena = m_catene.at(m_turni-1);
    m_suggerimenti[1] = aCatena.at(1).length();
    m_suggerimenti[2] = aCatena.at(2).length();
    updateCatena();
}

void Uncover::updateCatena()
{
    m_catena.clear();
    QList<QString> aCatena = m_catene.at(m_turni-1);
    for (int i=0; i<aCatena.size(); i++) {
        QString s = aCatena.at(i);
        if (i == 0 or i == 3) {
            m_catena << QVariant(s.toUpper());
        }
        else {
            QString var = s.left(m_suggerimenti[i]);
            for (int j=m_suggerimenti[i]; j<s.size(); j++)
                var += "-";

            m_catena << QVariant(var.toUpper());
        }
    }

    emit catenaChanged();
    emit puntiChanged();
}

void Uncover::change()
{
    if (m_turni == m_catene.count()) {
        qDebug() << "CATENE TERMINATE";
        return;
    }

    QList<QString> aCatena = m_catene.at(m_turni);
    m_catena.clear();
    for (int i=0; i<aCatena.size(); i++) {
        QString s = aCatena.at(i);
        if (i == 0 or i == 3) {
            m_suggerimenti[i] = s.size();
            m_catena << QVariant(s.toUpper());
        }
        else {
            m_suggerimenti[i] = 1;
            QString var = s.left(1);
            for (int j=1; j<s.size(); j++)
                var += "-";

            m_catena << QVariant(var.toUpper());
        }
    }
    m_turni++;
    emit catenaChanged();
    m_punti = MAX_PUNTI;
    emit puntiChanged();
}

void Uncover::randomizer()
{
    //unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    unsigned seed = 74;
    std::shuffle(m_catene.begin(), m_catene.end(), std::default_random_engine(seed));
}

