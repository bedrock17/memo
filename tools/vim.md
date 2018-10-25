VIM
==
```bash
sudo apt install vim
```

## installing vim-plug
```bash
curl -fLo ~/.vim/autoload/plug.vim --create-dirs \
    https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim
```


## VIMRC
```vim
call plug#begin('~/.vim/plugged')

Plug 'NLKNguyen/papercolor-theme'
Plug 'junegunn/vim-easy-align'
Plug 'scrooloose/nerdtree', { 'on': 'NERDTreeToggle' }
Plug 'octol/vim-cpp-enhanced-highlight'
Plug 'junegunn/goyo.vim'
Plug 'terryma/vim-multiple-cursors'
Plug 'bling/vim-airline'


call plug#end()

colorscheme PaperColor

let g:cpp_class_scope_highlight = 1
let g:cpp_member_variable_highlight = 1
let g:cpp_class_decl_highlight = 1

set background=dark
set expandtab ts=4 sw=4 ai
set number
set laststatus=2
set autoindent
set cindent
set backspace=2
set lazyredraw
set cul
set ttyfast
set mouse=nicr
set hlsearch
set showmatch
```
