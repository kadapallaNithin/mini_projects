## Battery Alerts
Plays audio based on battery crossing threshold 
-near full (>90%) (implemented)
-near empty (>15%) (not intrested because default notification is enough)

Stops playing if required action is taken i.e
-plugging in the charger when near empty (inherently not intrested)
-plugging out the charger when near full (implemented)

### prerequisites and setup
-install vlc
-have supported file format and set audio_path in file
-periodically (1min, 5min or 10min) run the script for example using crontab

### Some useful commands for debugging
-see vlc processes
    ps -e | grep "vlc"
-see jobs that are run by cron
    ps -o pid,sess,cmd afx | egrep -A20 "( |/)cron( -f)?$"
-see cron log
    grep CRON /var/log/syslog
