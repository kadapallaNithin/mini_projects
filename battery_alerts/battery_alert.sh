capacity=`cat /sys/class/power_supply/BAT1/capacity`
charging=`cat /sys/class/power_supply/ACAD/online`
if [ $charging ] && [ $capacity -gt 90 ]
then
    home_dir="/home/nithin/battery" # don't add trailing /
    audio_path=$home_dir/Shiva_Tandava_Stotram.mp3
    log_path=$home_dir/alert.log
    #echo "starting audio.. and log_path is " $log_path
    cvlc --play-and-exit $audio_path &
    playing=1 #`cat $home_dir/battery/playing.txt`
    while [ $playing = 1 ]
    do
        charging=`cat /sys/class/power_supply/ACAD/online`` #$home_dir/battery/y.txt`
        if [ $charging = '0' ]
        then
            #echo `date` "not charging" >> $log_path
#            x=`ps -e | grep "vlc" | grep "*"`
            for PID in `ps x | grep $audio_path | awk '/?/ { print $1 }'`
            do
                echo $PID >> $log_path
                kill $PID
            done
            playing=0
        else
            sleep 2
        fi
    done