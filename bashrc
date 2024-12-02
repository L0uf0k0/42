# ~/.bashrc: executed by bash for non-login shells.
# see /usr/share/doc/bash/examples/startup-files (in the package bash-doc)
# for examples

# If not running interactively, don't do anything
case $- in
    *i*) ;;
      *) return;;
esac

# don't put duplicate lines or lines starting with space in the history.
# See bash(1) for more options
HISTCONTROL=ignoreboth

# append to the history file, don't overwrite it
shopt -s histappend

# for setting history length see HISTSIZE and HISTFILESIZE in bash(1)
HISTSIZE=1000
HISTFILESIZE=2000

# check the window size after each command and, if necessary,
# update the values of LINES and COLUMNS.
shopt -s checkwinsize

# If set, the pattern "**" used in a pathname expansion context will
# match all files and zero or more directories and subdirectories.
#shopt -s globstar

# make less more friendly for non-text input files, see lesspipe(1)
[ -x /usr/bin/lesspipe ] && eval "$(SHELL=/bin/sh lesspipe)"

# set variable identifying the chroot you work in (used in the prompt below)
if [ -z "${debian_chroot:-}" ] && [ -r /etc/debian_chroot ]; then
    debian_chroot=$(cat /etc/debian_chroot)
fi

# set a fancy prompt (non-color, unless we know we "want" color)
case "$TERM" in
    xterm-color|*-256color) color_prompt=yes;;
esac

# uncomment for a colored prompt, if the terminal has the capability; turned
# off by default to not distract the user: the focus in a terminal window
# should be on the output of commands, not on the prompt
#force_color_prompt=yes

if [ -n "$force_color_prompt" ]; then
    if [ -x /usr/bin/tput ] && tput setaf 1 >&/dev/null; then
	# We have color support; assume it's compliant with Ecma-48
	# (ISO/IEC-6429). (Lack of such support is extremely rare, and such
	# a case would tend to support setf rather than setaf.)
	color_prompt=yes
    else
	color_prompt=
    fi
fi

if [ "$color_prompt" = yes ]; then
    PS1='${debian_chroot:+($debian_chroot)}\[\033[01;32m\]\u@\h\[\033[00m\]:\[\033[01;34m\]\w\[\033[00m\]\$ '
else
    PS1='${debian_chroot:+($debian_chroot)}\u@\h:\w\$ '
fi
unset color_prompt force_color_prompt

# If this is an xterm set the title to user@host:dir
case "$TERM" in
xterm*|rxvt*)
    PS1="\[\e]0;${debian_chroot:+($debian_chroot)}\u@\h: \w\a\]$PS1"
    ;;
*)
    ;;
esac

# enable color support of ls and also add handy aliases
if [ -x /usr/bin/dircolors ]; then
    test -r ~/.dircolors && eval "$(dircolors -b ~/.dircolors)" || eval "$(dircolors -b)"
    alias ls='ls --color=auto'
    #alias dir='dir --color=auto'
    #alias vdir='vdir --color=auto'

    alias grep='grep --color=auto'
    alias fgrep='fgrep --color=auto'
    alias egrep='egrep --color=auto'
fi

# colored GCC warnings and errors
#export GCC_COLORS='error=01;31:warning=01;35:note=01;36:caret=01;32:locus=01:quote=01'

# some more ls aliases
alias ll='ls -alF'
alias la='ls -A'
alias l='ls -CF'

# Add an "alert" alias for long running commands.  Use like so:
#   sleep 10; alert
alias alert='notify-send --urgency=low -i "$([ $? = 0 ] && echo terminal || echo error)" "$(history|tail -n1|sed -e '\''s/^\s*[0-9]\+\s*//;s/[;&|]\s*alert$//'\'')"'

# Alias definitions.
# You may want to put all your additions into a separate file like
# ~/.bash_aliases, instead of adding them here directly.
# See /usr/share/doc/bash-doc/examples in the bash-doc package.

if [ -f ~/.bash_aliases ]; then
    . ~/.bash_aliases
fi

# enable programmable completion features (you don't need to enable
# this, if it's already enabled in /etc/bash.bashrc and /etc/profile
# sources /etc/bash.bashrc).
if ! shopt -oq posix; then
  if [ -f /usr/share/bash-completion/bash_completion ]; then
    . /usr/share/bash-completion/bash_completion
  elif [ -f /etc/bash_completion ]; then
    . /etc/bash_completion
  fi
fi

alias francinette=/home/l/francinette/tester.sh
alias paco=/home/l/francinette/tester.sh




# Prompt coloré et informatif
PS1='\[\e[1;32m\]\u@\h \[\e[1;34m\]\w\[\e[0m\] \$ '

# Auto-completion avancée
if [ -f /etc/bash_completion ]; then
    . /etc/bash_completion
fi

# Forcer l'activation des couleurs dans `ls`
export CLICOLOR=1
export LSCOLORS=GxFxCxDxBxegedabagaced

# Alias pour git
alias gs='git status'
alias ga='git add -A'
alias gc='git commit -m'
alias gp='git push'
alias gco='git checkout'
alias gl='git log --oneline --graph --decorate --pretty -n 5'

alias gccf='gcc -fsanitize=address -g3 -Wall -Wextra -Werror'
alias rb='source ~/.bashrc'

# Recherche et ouverture de fichiers ou de dossiers
function fe() {
  local result=$(find . -name "*$1*" -print -quit)  # Trouver le premier résultat correspondant
  if [ -d "$result" ]; then  # Si c'est un dossier
    cd "$result" && ls  # Ouvrir le dossier et lister son contenu
  elif [ -f "$result" ]; then  # Si c'est un fichier
    ${EDITOR:-vim} "$result"  # Ouvrir le fichier avec l'éditeur
  else
    echo "Aucun fichier ou dossier correspondant trouvé."
  fi
}

# Recherche dans tout le système et ouverture de fichiers ou dossiers
function feg() {
  local result=$( find / -name "*$1*" -print -quit 2>/dev/null)  # Trouver le premier résultat dans tout le système
  if [ -d "$result" ]; then  # Si c'est un dossier
    cd "$result" && ls  # Ouvrir le dossier et lister son contenu
  elif [ -f "$result" ]; then  # Si c'est un fichier
    ${EDITOR:-vim} "$result"  # Ouvrir le fichier avec l'éditeur
  else
    echo "Aucun fichier ou dossier correspondant trouvé."
 fi
}

alias vimrc='feg .vimrc'
alias bashrc='feg .bashrc'

# Afficher un message de bienvenue ou une citation aléatoire
function welcome() {
	echo "         _nnnn_	  		\` : | | | |:  ||  :     \`  :  |  |+|: | : : :|   .        \`              .
        dGGGGMMb     ,...............     \` : | :|  ||  |:  :    \`  |  | :| : | : |:   |  .                    :
       @p~qp~~qMb    | Hi there !   |         .' ':  ||  |:  |  '       \` || | : | |: : |   .  \`           .   :.
       M|@||@) M|   _;..............'                \`'  ||  |  ' |   *    \` : | | :| |*|  :   :               :|
       @,----.JM| -'		        *    *       \`  |  : :  |  .      \` ' :| | :| . : :         *   :.||
      JS^\__/  qKL		             .\`            | |  |  : .:|       \` | || | : |: |          | ||
     dZP        qKRb		      \'          .         + \`  |  :  .: .         '| | : :| :    .   |:| ||
    dZP          qKKb		         .                 .    \` *|  || :       \`    | | :| | :      |:| |
   fZP            SMMb		 .                .          .        || |.: *          | || : :     :|||
   HZM            MMMM		        .            .   . *        .  \` |||.  +        + '| |||  .  |\`
   FqM            MMMM		     .             *              .     +:\`|!             . ||||  :.||\`
 __| \".        |\dS\"qML	 +                            .                ..!|*          . | :\`||+ |||\`
 |    \`.       \| \`\' \Zq	     .                        +      : |||\`        .| :| | | |.| ||\`
_)      \.___.,\|     .'	       *     +   '               +  :|| |\`     :.+. || || | |:\`|| \`
\____   )MMMMMM|   .'		                                     ||\` .    ..|| | |: '\` \`| | |\`  +
     \`-'       \`--'  			  .       +++                      ||        !|!: \`       :| |"
	echo "
Bienvenue, $(whoami)!

	"
}
welcome

# Ajouter automatiquement sudo si tu l'as oublié
alias please='sudo $(history -p !!)'

alias gm='git clone git@github.com:L0uf0k0/42.git MAIN'
alias l='git@github.com:L0uf0k0/42.git'

clb() {
    if [ "$#" -ne 1 ]; then
        echo "Usage: clone_branch <branch-name> git@github.com:L0uf0k0/42.git"
        return 1
    fi
    local branch_name=$1
    git clone -b "$branch_name" "git@github.com:L0uf0k0/42.git" "$branch_name"
}

alias DE='cd Desktop'
alias D='cd ~'
alias bat='batcat'

alias 42u='"/mnt/c/Program Files/Google/Chrome/Application/chrome.exe" "https://profile.intra.42.fr/"'
alias gu='"/mnt/c/Program Files/Google/Chrome/Application/chrome.exe" "https://github.com/L0uf0k0/42"'
function reboot() {
	reset && source ~/.bashrc && cd ~
}

alias rf='rm -Rf'
alias re='clear'

function qs() {
    if [ "$#" -ne 1 ]; then
        echo "Usage: sc <search>"
        return 1
    fi
    local sc=$1
   	grep "$sc" -r
}
