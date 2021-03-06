\NeedsTeXFormat{LaTeX2e}
\ProvidesClass{tmanotes}[2018/03/21 Lecture Notes class]
\LoadClass[onecolumn, twoside, a4paper, 11pt]{memoir}

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

% Graphics
\RequirePackage{graphicx}

% Colors
\RequirePackage{pgfplots}
\pgfplotsset{compat=1.8}
\definecolor{darkblue}{HTML}{00688B}
\definecolor{darkgreen}{HTML}{6E8B3D}
\definecolor{cadet}{HTML}{DAE1FF}
\definecolor{salmon}{HTML}{FFB08A}

% Algorithms
\RequirePackage{algpseudocode}
\RequirePackage{algorithm}

\newenvironment{pseudo}
{
	\begin{algorithm}[H]
	\begin{algorithmic}
}
{
	\end{algorithmic}
	\end{algorithm}
}

\newenvironment{algo}[1]
{	\begin{algorithm}
  \caption{#1}
	\begin{algorithmic}
}
{
	\end{algorithmic}
	\end{algorithm}
}

\RequirePackage{enumitem}
\newenvironment{tmatsks}
{
	\begin{enumerate}[label=(\alph*), noitemsep]
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
	\begin{sltn}[Exercise \ref{tmaxrcs:#1} page \pageref{tmaxrcs:#1}]
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
