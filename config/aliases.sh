#!/usr/bin/env bash
# Source this file for the current terminal
#       source ~/hex_ws/src/hexapod/config/aliases.sh
# OR Add it to your .bashrc to auto-source once a terminal opens
#       echo "source ~/hex_ws/src/hexapod/config/aliases.sh" >> ~/.bashrc


alias srcb='source ~/.bashrc'
alias sws='source devel/setup.bash'
alias swsx='source ~/hex_ws/devel/setup.bash'

alias kz='killall gazebo & killall gzserver & killall gzclient'

alias rlh="swsx; roslaunch hexapod hexapod.launch"
alias cdx='cd ~/hex_ws/src/hexapod/'

alias gitconRW="git config --global credential.helper 'cache --timeout=999999'; git config --global user.name 'rwbot'; git config --global user.email 'rwbotx@gmail.com'"
alias gitconKIRK="git config --global credential.helper 'cache --timeout=999999'; git config --global user.name 'Kirk Boyd'; git config --global user.email 'kirkland.boyd@trincoll.edu'"