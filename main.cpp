#include <QCoreApplication>
#include <QBluetooth.h>
#include <QLowEnergyController>
#include <QBluetoothDeviceInfo>
#include <QDebug>
//#include <QKeyEvent>
#include "device.cpp"

#ifdef Q_OS_WIN
    #define WINVER 0x0502
    #include <Windows.h>
#endif

void sendKeyEventToSystem(Qt::Key qtKey) {
//function of emulation of key press. qtKey - key type
#ifdef Q_OS_WIN
   INPUT ip; //the input equipment
   ip.type = INPUT_KEYBOARD;
   ip.ki.wScan = 0;
   ip.ki.time = 0;
   ip.ki.dwExtraInfo = 0;

   //depending on key type
   switch (qtKey) {
   case Qt::Key_MediaPrevious:
       qDebug() << "PREV key pressed!";
       ip.ki.wVk = VK_MEDIA_PREV_TRACK; //the previous track
       break;
   case Qt::Key_MediaTogglePlayPause:
       qDebug() << "PLAY key pressed!";
       ip.ki.wVk = VK_MEDIA_PLAY_PAUSE; //for switching of a regime of playback
       break;
   case Qt::Key_MediaNext:
       qDebug() << "NEXT key pressed!";
       ip.ki.wVk = VK_MEDIA_NEXT_TRACK; //the following track
       break;
   default:
       qDebug() << "UNKNOWN key pressed!";
       return;
       break;
   }
   //we send key press event
   ip.ki.dwFlags = 0;
   SendInput(1, &ip, sizeof (INPUT));
   //and then key releases
   ip.ki.dwFlags = KEYEVENTF_KEYUP;
   SendInput(1, &ip, sizeof (INPUT));
#endif
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug() << "DoReMote Driver - Retro Edition\n";

    //BLE Device instantiation
    Device ble;
    ble.startDeviceDiscovery();

    qDebug() << "Discovery started!";

    //If previous failed, ble.state is not set
    if (ble.state())
    {
        qDebug() << "Got a device!";
    }

    //QBluetoothDeviceInfo
    //QLowEnergyController ble();

    //sendKeyEventToSystem(Qt::Key_MediaTogglePlayPause);
    qDebug() << "Done!";
    return a.exec();
}
