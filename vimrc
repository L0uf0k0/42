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
nnoremap <G-Up> gg
nnoremap <G-Down> G
nnoremap <G-Left> ^
nnoremap <G-Right> g

colorscheme desert "torte elflord industry zenburn

function! RunNorminette()
  if &filetype == 'c'
    " Ouvre une fenêtre en vsplit
    "vsplit

    " Ouvre un terminal dans le vsplit et exécute norminette sur le fichier actuel
    execute 'terminal norminette %'
  else
    echo "Ce n'est pas un fichier C"
  endif
endfunction

" Mappe une commande pour lancer la fonction
command! Norminette call RunNorminette()
nmap <leader>n :call RunNorminette()<CR>


