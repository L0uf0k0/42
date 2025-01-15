#########################
#        .ZSHRC         #
#########################

HISTFILE=~/.zsh_history
HISTSIZE=4096
SAVEHIST=16384

# Keybinds

bindkey -e
bindkey "^[[3~" delete-char
bindkey "^e" end-of-line
bindkey "^a" beginning-of-line

# Options

unsetopt menu_complete
setopt append_history
setopt prompt_subst
setopt auto_menu
setopt always_to_end
setopt complete_in_word
setopt hist_ignore_dups
setopt inc_append_history

# Plugins

if [ $(uname) = "Linux" ]; then
	export UNAME="$(grep "^NAME=" /etc/os-release | cut -d'"' -f2)"
else
	export UNAME="Darwin"
fi

for file in $HOME/zshrc.d/*; do
	source $file
done
unset UNAME

#Launch!

rm -rf "$HOME/.local/state/nvim/swap"
source <(fzf --zsh)
eval "$(starship init zsh)"
eval "$(zoxide init --cmd cd zsh)"
fastfetch

# Alias pour git
alias gs='git status'
alias ga='git add -A'
alias gc='git commit -m'
alias gp='git push'
alias gco='git checkout'
alias gl='git log --oneline --graph --decorate --pretty -n 5'

alias gccf='gcc -fsanitize=address -g3 -Wall -Wextra -Werror'
alias rb='re; source ~/.zshrc'

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
  local result=$( find ~ -name "*$1*" -print -quit 2>/dev/null)  # Trouver le premier résultat dans tout le système
  if [ -d "$result" ]; then  # Si c'est un dossier
    cd "$result" && ls  # Ouvrir le dossier et lister son contenu
  elif [ -f "$result" ]; then  # Si c'est un fichier
    ${EDITOR:-vim} "$result"  # Ouvrir le fichier avec l'éditeur
  else
    echo "Aucun fichier ou dossier correspondant trouvé."
 fi
}

alias vimrc='vim ~/.vimrc'
alias bashrc='feg .zshrc'
alias zshrc='feg .zshrc'


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

alias rf='rm -Rf'
alias cp='cp -r'
alias re='clear'

function qs() {
    if [ "$#" -ne 1 ]; then
        echo "Usage: sc <search>"
        return 1
    fi
    local sc=$1
   	grep "$sc" -r
}

alias e='cd ~/42; vim'


USER=l
export USER
MAIL=l@student.42.fr
export MAIL
