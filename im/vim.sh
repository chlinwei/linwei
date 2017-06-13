#!/bin/bash


#备份.bashrc
cp ~/.bashrc  ~/.bashrc.bk



#设置默认编辑器为vim
grep "EDITOR=/usr/bin/vim" ~/.bashrc  >/dev/null 2>&1
[ $? != 0 ]&& { echo "export EDITOR=/usr/bin/vim" >> ~/.bashrc; } 




#配置.vimrc
cat > ~/.vimrc << EOF
let mapleader=";"
nnoremap <leader>" viw<esc>a"<esc>hbi"<esc>lel
nnoremap <leader>' viw<esc>a'<esc>hbi'<esc>lel
nnoremap <leader>( viw<esc>a)<esc>hbi(<esc>lel
"注视一行
"nnoremap <leader>cc viw<esc>a*/<esc>hbi/*<esc>lel  

"基本配置-----------------------------------
set nu
set title
inoremap jk <esc>
set incsearch
set hlsearch "表示高亮搜索单词
set ignorecase
set ruler
set wildmenu
set laststatus=2
set cursorline
syntax enable
syntax on
filetype indent on
set tabstop=4
set shiftwidth=4
set softtabstop=4
set nocompatible "不兼容模式
nnoremap <leader>w <C-c>:wq<enter>
nnoremap - _
vnoremap <leader>w <C-c>:wq<enter>
nnoremap <leader>q <esc>:q!<enter>
vnoremap <leader>q <esc>:q!<enter>
nnoremap <C-h> <C-w>h
nnoremap <C-l> <C-w>l
nnoremap <C-j> <C-w>j
nnoremap <C-k> <C-w>k

"开启文件类型检查
filetype on
"根据检查到的不同类型加载对应的插件
filetype plugin on

"pathogen配置
runtime bundle/vim-pathogen/autoload/pathogen.vim
execute pathogen#infect()

"delimitMate配置
"-------delimate.vim 0----
"选择补全的括号
let delimiMate_autoclose = 1
let delimiMate_matchpairs = "(:),[:],{:}"  
"按enter键
let delimitMate_expand_cr = 1
"let delimitMate_expand_space = 1
let delimitMate_quotes = "\" ' \`"

"nerdcommenter配置
"在注释// 后面添加一个空格
let g:NERDSpaceDelims = 1
"将行注释符左对齐
let g:NERDDefaultAlign = 'left'
"修正注释后面尾随的空格
let g:NERDTrimTrailingWhitespace = 1
"visual模式下<leader>ci能选择复制

EOF





#配置.vim
mkdir -p ~/.vim/bundle
cd ~/.vim/bundle

ls |grep vim-pathogen >/dev/null 2>&1
[ $? != 0 ]&&git clone https://github.com/tpope/vim-pathogen >/dev/null 2>&1

ls |grep vim-surround >/dev/null 2>&1
[ $? != 0 ]&&git clone  https://github.com/tpope/vim-surround

ls |grep delimitMate >/dev/null 2>&1
[ $? != 0 ]&&git clone https://github.com/Raimondi/delimitMate

ls |grep nerdcommenter >/dev/null 2>&1
[ $? != 0 ]&&git clone https://github.com/scrooloose/nerdcommenter

ls |grep vim-airline > /dev/null 2>&1
[ $? != 0 ]&&git clone https://github.com/vim-airline/vim-airline


#判断是否为root
name=`whoami`
[ $name != "root" ] && { echo "to install software,you must be root";exit; }

