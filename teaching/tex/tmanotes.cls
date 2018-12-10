\NeedsTeXFormat{LaTeX2e}
\ProvidesClass{tmanotes}[2018/03/21 Lecture Notes class]
\LoadClass[onecolumn, twoside, a4paper, 11pt]{memoir}

\newcommand{\tmacoursecode}{}
\newcommand{\tmacoursename}{}
\newcommand{\tmacourseshrt}{}
\newcommand{\tmacoursefull}{}
\newcommand{\settmacourse}[3]
{
\renewcommand{\tmacoursecode}{#1}
\renewcommand{\tmacoursename}{#2}
\renewcommand{\tmacourseshrt}{#3}
\renewcommand{\tmacoursefull}{\tmacoursecode\tmacoursename}
}
\RequirePackage[sectionbib]{bibunits}
\DeclareOption{assignment}
{
\pagestyle{headings}
\renewcommand{\chaptermark}[1]{ \markboth{{\small\tmacoursecode\;--\;\tmacourseshrt}}{} }
\renewcommand{\sectionmark}[1]{ \markboth{{\small\tmacoursecode\;--\;\tmacourseshrt}}{} }
\renewcommand\thesection{\arabic{section}}
\renewcommand\thetable{\arabic{section}}
}
\ProcessOptions\relax

\setcounter{secnumdepth}{2}
\setcounter{tocdepth}{2}

%
\RequirePackage{a4}
\RequirePackage[utf8]{inputenc}
\RequirePackage[T1]{fontenc}
\RequirePackage[english]{babel}

% Math Symbols
\RequirePackage{amsmath}
\RequirePackage{amssymb}
\RequirePackage{amsthm}
\RequirePackage{relsize}
\RequirePackage{xfrac}

% Graphics
\RequirePackage{graphicx}

% Colors
\RequirePackage{pgfplots}
\usepgfplotslibrary{dateplot}
\pgfplotsset{compat=1.8}
\definecolor{darkblue}{HTML}{00688B}
\definecolor{darkgreen}{HTML}{6E8B3D}
\definecolor{cadet}{HTML}{DAE1FF}
\definecolor{salmon}{HTML}{FFB08A}

\usepackage{bm}

% Algorithms
\RequirePackage{algpseudocode}
\RequirePackage{algorithm}

\newenvironment{tmapseudo}
{
	\begin{algorithm}[H]
	\begin{algorithmic}
}
{
	\end{algorithmic}
	\end{algorithm}
}

\newenvironment{tmaalgo}[1]
{
	\begin{algorithm}
  \caption{#1}
	\begin{algorithmic}
}
{
	\end{algorithmic}
	\end{algorithm}
}

\newenvironment{tmatable}[1]
{
	\begin{center}
	\bgroup
	\def\arraystretch{2}
	\begin{tabular}{#1}
}
{
	\end{tabular}
	\egroup
	\end{center}
}

\RequirePackage{enumitem}
\RequirePackage{hyperref}

\newenvironment{tmatsks}
{
	\begin{enumerate}[label=(\alph*), noitemsep]
}
{
	\end{enumerate}
}

\newenvironment{tmaproofitems}
{
	\begin{enumerate}[label=(\roman*), noitemsep]
}
{
	\end{enumerate}
}


\newenvironment{tmaxrcs}[2]
{
	\begin{xrcs}[#1]\label{tmaxrcs:#2}
  \hfill\break
}
{
	\end{xrcs}
}

\newenvironment{tmasltn}[1]
{
	\begin{sltn}[Exercise \ref*{tmaxrcs:#1} page \pageref{tmaxrcs:#1}]
  \hfill\break
}
{
	\end{sltn}
}

% Nomenclature
\RequirePackage[refpage]{nomencl}
\RequirePackage{makeidx}


\input{symbols}
\input{mathenv}
