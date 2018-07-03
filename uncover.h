#ifndef UNCOVER_H
#define UNCOVER_H

#include <QObject>
#include <QList>
#include <QString>
#include <QVariantList>

class Uncover : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVariantList catena READ catena NOTIFY catenaChanged)
    Q_PROPERTY(int punti READ punti NOTIFY puntiChanged)
public:

    explicit Uncover(const QString& filename, QObject* parent = 0);

    //void setCatena(const QQmlListProperty& aList);
    QVariantList catena() const;
    int punti() const { return m_punti; }

    void updateCatena();
    void randomizer();

public slots:
    void change();
    void suggerimento(const int i);
    void mostraTutto();

signals:
    void catenaChanged();
    void puntiChanged();

private:

    QList<QList<QString> > m_catene;
    QVariantList m_catena;
    int m_turni;
    QList<int> m_suggerimenti;

    int m_punti;
};

#endif // UNCOVER_H
