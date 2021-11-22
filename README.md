<!-- PROJECT LOGO -->
<br />
<p align="center">
  <a href="https://github.com/livingsu/Qt-minesweeper">
    <img src="pic/mine_step.jpg" alt="Logo" width="23">
  </a>

  <h3 align="center">QT-M</h3>

  <p align="center">
    Qt-minesweeper
    <br />
    <a href="https://github.com/livingsu/Qt-minesweeper"><strong>Explore QT-M Repository »</strong></a>
  </p>
</p>



<!-- TABLE OF CONTENTS -->
<details open="open">
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
      	<li><a href="#developers">Developers</a></li>
        <li><a href="#contributors">Contributors</a></li>
      </ul>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
      	<li><a href="#supported-platforms">Supported Platforms</a></li>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#cmake-options">CMake Options</a></li>
        <li><a href="#example-build">Example Build</a></li>
      </ul>
    </li>
    <li>
      <a href="#release-history">Release History</a>
    </li>
    <li>
      <a href="#meta">Meta</a>
    </li>
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
## About The Project

This project uses Linux's Netfilter Framework API to monitor network traffic and apply following rules:

This project simulates the minesweeper game that comes with the Windows.


## Developers

* <a href="https://github.com/livingsu">livingsu</a> - qq:1753843140


## Contributors

* <a href="https://github.com/malyjak">malyjak</a> - malyjak@protonmail.ch



<!-- GETTING STARTED -->
## Getting Started

You can build QT-M as any other project with a CMake-based build system: run the installed CMake on the sources of this repository with your preferred options and generators.


### Supported Platforms

* Windows


### Prerequisites

* Qt5 (5.15.2 recommended)
* CMake (>=3.20.0)
* MSBuild (16 recommended)



### CMake Options

Currently there is only one CMake option `MINESWEEPER_LANG` which can switch the language between English and Chinese. English is the default.



### Example Build

1) Create a binary folder (ex: `qtm_build`)

2) Open cmake-gui

3) Specify the source code location (ex: `C:/Projects/Qt-minesweeper`)

4) Specify the binary folder (ex: `C:/Projects/qtm_build`)

5) Configure

6) Select Visual Studio 17 2019 as the generator

7) Finish

8) Specify the Qt5_DIR option if needed (ex: `C:\Qt\5.15.2\msvc2019_64\lib\cmake\Qt5`)

9) Switch language if You desire

9) Configure until no red row occurs

10) Generate

11) Open Developer Tools and navigate to the build folder

12) `msbuild Minesweeper.sln`

13) Go to Debug folder and run main.exe



<!-- RELEASE HISTORY -->
## Release History

* 1.0
	* ADDITIONS: CMake and multilingual support.
	* CHANGES: Fixed Qt bugs.



<!-- META -->
## Meta

Qt实现的扫雷
教程：[用Qt实现扫雷](https://blog.csdn.net/livingsu/article/details/104774193)
