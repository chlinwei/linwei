#!/bin/bash


#备份.bashrc
cp ~/.bashrc  ~/.bashrc.bk

#禁止光标闪烁
gsettings set org.gnome.desktop.interface cursor-blink false 


#设置默认编辑器为vim
grep "EDITOR=/usr/bin/vim" ~/.bashrc  >/dev/null 2>&1
[ $? != 0 ]&& { echo "export EDITOR=/usr/bin/vim" >> ~/.bashrc; } 

#解决emacs里无法输入中文问题
grep LC_CTYPE=zh_CN.UTF-8 ~/.bashrc  >/dev/null 2>&1
[ $? != 0 ]&& { echo "export LC_CTYPE=zh_CN.UTF-8">> ~/.bashrc; } 

#设置man page的颜色
grep "man()" ~/.bashrc >/dev/null 2>&1 
if [ $? != 0 ];then
cat  >> ~/.bashrc << EOF
man() {
 env \
 LESS_TERMCAP_mb=\$(printf "\e[1;31m") \
 LESS_TERMCAP_md=\$(printf "\e[1;31m") \
 LESS_TERMCAP_me=\$(printf "\e[0m") \
 LESS_TERMCAP_se=\$(printf "\e[0m") \
 LESS_TERMCAP_so=\$(printf "\e[1;44;33m") \
 LESS_TERMCAP_ue=\$(printf "\e[0m") \
 LESS_TERMCAP_us=\$(printf "\e[1;32m") \
 man "\$@"
} 
EOF
fi

#使.bashrc生效
. ~/.bashrc

#配置.ideavimrc
cat > ~/.ideavimrc << EOF
set number
set hlsearch "表示高亮搜索单词
set incsearch "表示边输入便匹配
set noswapfile
"大小写忽略
set ignorecase
set smartcase
set encoding=utf-8
set fileformat=unix
set showmode
let mapleader=";"

nnoremap <leader>" viw<esc>a"<esc>hbi"<esc>lel
nnoremap <leader>' viw<esc>a'<esc>hbi'<esc>lel
nnoremap <leader>( viw<esc>a)<esc>hbi(<esc>lel 
nnoremap - _
set nowrap "设置不自动折行
set title
inoremap jk <esc>
set wildmenu "自身命令模式下补全

set laststatus=2
set cursorline
set tabstop=4
set shiftwidth=4 "自动缩进插入的空格数
set softtabstop=4 "使用或自动插入或删除相应的空格数
set smartindent

nnoremap <C-h> <C-w>h
nnoremap <C-l> <C-w>l
nnoremap <C-j> <C-w>j
nnoremap <C-k> <C-w>k
nnoremap <leader>w <C-c>:wq<enter>
vnoremap <leader>w <C-c>:wq<enter>
nnoremap <leader>q <esc>:q!<enter>
nnoremap - _
nnoremap a A
nnoremap <leader><space> :noh<cr>
nnoremap <A--> gT
map <A-=> gt

syntax on
filetype indent on "根据文件类型进行自动缩进
filetype on "开启文件类型侦测 filetype plugin on 

"运行当前文件
nnoremap <leader>r :action RunClass<cr>  
nnoremap <leader>gg :action GotoDeclaration<CR> "查找定义
nnoremap <leader>gb :action Back<CR> "返回
nnoremap <leader>go :action QuickDocumentation<CR>
nnoremap <leader>ge :action GoToErrorGroup<CR>
nnoremap <leader>gt :action GotoTypeDeclaration<CR>
nnoremap <leader>gc :action GotoClass<CR>
nnoremap <leader>ff :action GotoFile<CR> "查找文件全局的
nnoremap <leader>gs :action GotoSuperMethod<CR>
nnoremap <leader>ga :action GotoAction<CR>
nnoremap <leader>ne :action NewElement<CR> "新建文件目录等
nnoremap <leader>nn :action NewFile<CR> "新建文件
nnoremap <leader>np :action NewDirectoryProject<CR> "新建工程
nnoremap <leader>nd :action NewDir<CR>新建目录
EOF


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

#下载软件
apt install -y vim git  sysstat flashplugin-installer
