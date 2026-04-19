# EasyX_Plane_Wars

![C++](https://img.shields.io/badge/Language-C++-blue.svg)
![Graphics](https://img.shields.io/badge/Library-EasyX-green.svg)
![Platform](https://img.shields.io/badge/Platform-Windows-lightgrey.svg)

## 🌟 项目简介
这是一个基于 **C++** 开发的经典街机风飞机大战游戏。项目采用自研的消息驱动游戏框架，深入应用了面向对象（OOP）的设计思想，实现了敌机波次管理、子弹物理模拟以及精细的碰撞检测系统。

---

## 🎬 游戏演示
<div align="center">
  <img src="./飞机大战开发/res/Plane_Wars_demo.gif" width="25%" alt="飞机大战游戏演示">
  <p><em>项目运行演示视频</em></p>
</div>  

---

## 🛠️ 核心技术亮点

### 1. 消息驱动式框架设计 (Message-Driven Architecture)
底层基于 `Win32 API` 消息泵封装了通用框架 `CGameFrame`，利用 `std::map` 实现了消息映射机制。
- **解耦**：将 Windows 繁琐的消息处理与游戏业务逻辑完全分离。
- **高效**：通过双缓冲技术（`BeginBatchDraw` / `EndBatchDraw`）解决了 2D 游戏常见的画面闪烁问题。

### 2. OOP 多态与资源复用
- **多态应用**：通过Foe基类派生出大、中、小三种机型，并在运行时利用 **RTTI (运行时类型识别)** 动态调整不同敌机的物理属性（如速度、血量）。
- **精灵表裁剪**：通过坐标偏移技术，实现了一张贴图支持多种爆炸状态和机型展示，优化了 GPU 显存占用。

### 3. 高效对象池管理
使用 `std::list` 容器维护同屏的大量弹幕与敌机对象。
- **安全删除**：严格遵循 STL 迭代器操作规范，确保对象在越界或碰撞后的实时销毁与内存回收。
- **碰撞算法**：实现了基于 AABB 改进的多点碰撞检测，确保高速运动下的判定准确性。

---
