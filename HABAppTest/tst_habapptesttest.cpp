#include <QString>
#include <QtTest>

class HABAppTestTest : public QObject
{
    Q_OBJECT

public:
    HABAppTestTest();

private Q_SLOTS:
    void testCase1();
};

HABAppTestTest::HABAppTestTest()
{
}

void HABAppTestTest::testCase1()
{
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(HABAppTestTest)

#include "tst_habapptesttest.moc"
