set number
syntax on
set autoindent
set showmode
set ruler
set showcmd
set mouse=a
map <C-m> :resize<CR>
let g:user42 = 'malapoug'
let g:mail42 = 'malapoug@student.42lausanne.ch'
set clipboard=unnamedplus

autocmd Filetype c inoremap <F2> void ft_()<CR>{<CR><Tab><CR>}<C-d>
autocmd Filetype c inoremap <F3> while (i < 0)<CR>{<CR><Tab><CR>i++;<CR>}<C-d>
autocmd Filetype c inoremap <F4> int main()<CR>{<CR><Tab>ft_();<CR>}<C-d>

colorscheme desert "torte elflord industry zenburn
set splitright         " Ouvrir les fenêtres verticalement à droite

nmap <leader>n :terminal norminette %<CR>

autocmd BufWritePre * %s/\s\+$//e  " Supprime les espaces en fin de ligne avant de sauvegarder

set list  " Affiche les espaces et tabulations
set listchars=tab:·\ ,trail:•  " Définissez les symboles pour tabulations et espaces

nnoremap \j :12,$s/    /\t/g<CR>
nnoremap \k :15,$g/^$/d<CR>
nnoremap <C-w> :term<CR>
tnoremap <C-q> <C-\><C-n>:bdelete!<CR>
nnoremap <C-r> :%s///g<Left><Left><Left>

"inoremap ( ()<Left>  " Auto-ferme les parenthèses
"inoremap { {}<Left>  " Auto-ferme les accolades
"inoremap [ []<Left>  " Auto-ferme les crochets
"nnoremap <leader>c :s/^/\/\//<CR>  " Commente une ligne en ajoutant "//"
"nnoremap <leader>u :s/^\/\///<CR>  " Décommente une ligne en supprimant "//"
"nnoremap <leader>c :w<CR>:!gcc % -o %:r && ./%:r<CR>  " Compile et exécute le programme C
"Plug 'preservim/tagbar'
"nnoremap <leader>t :TagbarToggle<CR>  " Ouvre/ferme la Tagbar



