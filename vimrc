set background=dark
set autoindent
set number
set ruler
syntax enable
set rulerformat=%l-%v
let g:user42 = 'malapoug'
let g:mail42 = 'malapoug@student.42lausanne.ch'
set mouse=a
set showmode
set showcmd
set mouse=a
set termwinsize=30x0

autocmd BufWritePre * %s/\s\+$//e  " Supprime les espaces en fin de ligne avant de sauvegarder

set list  " Affiche les espaces et tabulations
set listchars=tab:·\ ,trail:•  " Définissez les symboles pour tabulations et espaces

"terminal
nnoremap <C-Tab> :tabn<CR>
nnoremap <C-z> :term<CR>
tnoremap <C-q> <C-\><C-n>:bdelete!<CR>

"header/norminette
nnoremap <F1> :Stdheader<CR>
nnoremap <F2> :term norminette %<CR>
nnoremap <F3> :vsplit . \| vertical resize 20<CR>
nnoremap <F4> :below term<CR>
"nnoremap <F5> :term zsh -c "make fclean; make debug ./"

"search
nnoremap <C-s> :%s///g<Left><Left><Left>

"replace spaces by tabs
nnoremap \j :12,$s/    /\t/g<CR>
nnoremap \k :15,$g/^$/d<CR>


call plug#begin('~/.vim/plugged')

Plug 'morhetz/gruvbox'
Plug 'ryanoasis/vim-devicons'
Plug 'dense-analysis/ale'
Plug 'mhinz/vim-startify'
Plug 'preservim/tagbar'

call plug#end()

nmap <F8> :TagbarToggle<CR>
let g:tagbar_compact = 1

let g:startify_lists = [
      \ { 'type': 'files',     'header': ['   Recent Files']       },
      \ { 'type': 'sessions',  'header': ['   Sessions']          },
      \ { 'type': 'bookmarks', 'header': ['   Bookmarks']         },
      \ ]
let g:startify_session_dir = '~/.vim/sessions'
let g:ale_linters = {
\   'c': ['gcc', 'clang', 'cppcheck', 'norminette'],
\}
let g:ale_linters_explicit = 1
let g:ale_enabled = 1
let g:ale_lint_on_save = 1
let g:ale_lint_on_text_changed = 'always'

let g:ale_fix_on_save = 1 " (optionnel) pour corriger automatiquement si possible

let g:ale_sign_error = '✗'      " Symbole pour les erreurs
let g:ale_sign_warning = '⚠'    " Symbole pour les avertissements
let g:ale_set_signs = 1  " Afficher les signes dans les marges (1) ou non (0)


" Configurer Gruvbox
set background=dark   " Pour activer le mode sombre
let g:gruvbox_contrast_dark='hard'
let g:gruvbox_italicize_comments = 0
let g:gruvbox_improved_strings=0
let g:gruvbox_improved_warnings=1

colorscheme gruvbox    " Appliquer le thème Gruvbox
" Activer la syntaxe et le thème Gruvbox
" Améliorer les couleurs pour les terminaux 256 couleurs
set t_Co=256

" Optionnel : Désactiver les couleurs de fond pour une meilleure lisibilité
let g:gruvbox_transparent_bg=1

" Configurations pour Netrw
let g:netrw_banner = 0            " Désactiver la bannière en haut
let g:netrw_liststyle = 3         " Affichage en arbre
let g:netrw_winsize = 25          " Taille de la fenêtre de navigation
let g:netrw_browse_split = 4          " Ouvre le fichier dans la precedente fenrtre


" Activer la coloration syntaxique
let g:netrw_syntax_enable = 1
" Ajouter des icônes (nécessite un terminal avec support des caractères Unicode)
autocmd FileType netrw setlocal conceallevel=3 concealcursor=n

highlight NetrwDir ctermfg=LightBlue  guifg=#83a598
highlight NetrwLink ctermfg=Blue guifg=#fabd2f
highlight NetrwcLabel ctermfg=Red guifg=#fabd2f


autocmd FileType netrw call CustomizeNetrwColors()

function! CustomizeNetrwColors()
    " Couleur pour les fichiers .c
    syntax match NetrwCFile "\v.*\.c$"
    syntax match NetrwCFile "\v.*\.c\*$"
    highlight NetrwCFile ctermfg=5 guifg=#83a598

    " Couleur pour les fichiers .h
    syntax match NetrwHFile "\v.*\.h$"
    highlight NetrwHFile ctermfg=36 guifg=#b8bb26

    " Couleur pour les Makefile
    syn match netrwMakeFile	"\<[mM]akefile\>\|\(\S\+ \)*\S\+\.mak\>"		contains=netrwTreeBar,@NoSpell
    highlight NetrwMakefile ctermfg=DarkBlue guifg=#fb4934
endfunction

    "syntax match NetrwMakefile "\v(^|/)Makefile"
    "highlight NetrwMakefile ctermfg=12 guifg=#b8bb26

