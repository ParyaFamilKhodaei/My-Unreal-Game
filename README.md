# Unreal Engine 5 — C++ Action Game & AI Prototype
https://github.com/user-attachments/assets/ed4af5d6-6a0b-47e7-ac2e-d9097ddf4cbe

> A C++-based third-person action game developed in Unreal Engine 5, with a focus on gameplay programming, enemy AI, navigation, perception, and state-based decision making.

**Project Status:** In Development  
**Engine:** Unreal Engine 5.7  
**Language:** C++  
**Development Environment:** Visual Studio / Unreal Engine  
**Primary Focus:** Gameplay Programming · Game AI · Navigation · AI Decision Making

---

## 🎮 Overview

This project is a third-person action game developed from the ground up as a practical exploration of gameplay programming and artificial intelligence in interactive environments.

Rather than treating the project only as a game, I use it as a foundation for experimenting with **autonomous game agents** — particularly how an enemy perceives the player, changes its behavioral state, navigates the environment, and selects actions based on the current situation.

The project is written primarily in **C++ within Unreal Engine**, with the goal of keeping gameplay and AI logic explicit and extensible for future research-oriented experiments.

---

## 🤖 Enemy AI

The enemy system is currently implemented as a **state-based reactive AI**.

An enemy can:

- Patrol between designated locations
- Perceive the player using Unreal Engine's Pawn Sensing system
- Detect the player within a configurable sight radius
- Transition from patrolling to chasing
- Navigate toward a target using Unreal Engine's AI navigation system
- Enter an attack state when the player is within attack range
- Lose interest when the target moves outside the combat radius
- React to incoming damage and pursue the attacking character
- Change movement speed according to its current behavior
- Select different patrol targets to introduce variation in movement
- Respond to combat events through health, hit reactions, and death states

The core AI loop is implemented in C++ rather than being hidden entirely inside Blueprint logic.

### Behavioral States

The current enemy behavior can be summarized as:

```text
                 ┌─────────────┐
                 │  PATROLLING │
                 └──────┬──────┘
                        │
                  Player detected
                        │
                        ▼
                 ┌─────────────┐
                 │   CHASING   │
                 └──────┬──────┘
                        │
                 Player in range
                        │
                        ▼
                 ┌─────────────┐
                 │   ATTACKING │
                 └──────┬──────┘
                        │
              Target lost / too far
                        │
                        ▼
                 ┌─────────────┐
                 │  PATROLLING │
                 └─────────────┘
```

This architecture provides a simple baseline for future experiments with more sophisticated decision-making methods.

---

## 🧠 AI Architecture

The current implementation deliberately provides a **non-learning baseline**.

The enemy makes decisions from observable game-state information such as:

- Distance to the player
- Player visibility
- Current enemy state
- Combat radius
- Attack radius
- Patrol targets
- Damage events

For example, the AI distinguishes between:

```text
Target outside combat radius
        ↓
     Patrol

Target detected
        ↓
     Chase

Target inside attack radius
        ↓
     Attack

Enemy receives damage
        ↓
  Identify attacker
        ↓
     Chase
```

This baseline is particularly useful as a starting point for future Game AI research because learned or adaptive agents can be compared against a deterministic rule-based agent.

---

## 🧩 Technical Implementation

### Enemy Perception

Enemy perception is implemented using Unreal Engine's `UPawnSensingComponent`.

The current configuration includes:

- Configurable sight radius
- Configurable peripheral vision
- Player detection callback
- Target acquisition
- Combat target tracking

```cpp
PawnSensing->SightRadius = 4000.f;
PawnSensing->SetPeripheralVisionAngle(45.f);
```

When the player is detected, the enemy acquires the player as its combat target and transitions into a chasing behavior.

---

### Navigation

Enemy movement is handled through Unreal Engine's AI navigation system and `AAIController`.

The project uses `FAIMoveRequest` to move enemies toward actors:

```cpp
FAIMoveRequest MoveRequest;
MoveRequest.SetGoalActor(Target);
MoveRequest.SetAcceptanceRadius(50.f);

EnemyController->MoveTo(MoveRequest);
```

This separates the **decision of where the agent should move** from the underlying navigation system responsible for finding a path.

---

### State-Based Decision Making

The enemy maintains explicit behavioral states:

```text
EES_Patrolling
EES_Chasing
EES_Attacking
```

State transitions are triggered by perception, distance checks, and combat events.

This makes the AI behavior easier to inspect, modify, and extend toward more sophisticated decision-making architectures.

---

## ⚔️ Combat System

The game also contains a C++ gameplay framework for:

- Character combat
- Weapon interaction
- Attack montages
- Hit reactions
- Health and damage
- Directional hit reactions
- Enemy health visualization
- Death states
- Multiple attack and death animations

The shared `ABaseCharacter` class provides common combat functionality, while the player character and enemy extend it for their specific behaviors.

---

## 🏗️ Code Architecture

The project follows a modular C++ structure:

```text
Source/
└── Slash/
    ├── Public/
    │   ├── Characters/
    │   ├── Components/
    │   ├── Enemy/
    │   ├── HUD/
    │   ├── Interfaces/
    │   ├── Items/
    │   ├── Pawns/
    │   └── Breakable/
    │
    └── Private/
        └── ...
```

Important gameplay systems are separated into dedicated classes and components rather than being implemented as one monolithic character class.

---

## 🔬 Research-Oriented Direction

One of my main motivations for developing this project is to bridge **game development and artificial intelligence**.

The current rule-based enemy provides a controllable baseline for future research experiments such as:

- Reinforcement Learning for combat agents
- Adaptive enemy behavior
- Learning from player behavior
- Utility-based decision making
- Behavior Trees and hierarchical decision systems
- Player modeling
- Dynamic difficulty adjustment
- Multi-agent game environments
- Comparing learned policies against scripted agents

A particularly interesting direction is to replace or augment the current deterministic decision system with a learning-based agent and evaluate whether the resulting behavior becomes more adaptive to different player strategies.

---

## 🛠️ Technologies

- **Unreal Engine 5.7**
- **C++**
- **Visual Studio**
- Unreal Engine AI Navigation
- Pawn Sensing / Perception
- Animation Montages
- Collision & Damage Systems
- Git / GitHub
- Git LFS

---

## 📁 Repository Structure

The repository contains the main Unreal Engine project files and C++ source code required to inspect the implementation.

```text
My-Unreal-Game/
├── Config/
├── Content/
├── Source/
├── .gitattributes
├── .gitignore
├── Slash.uproject
└── test.mp4
```

The `Source/` directory contains the C++ gameplay and AI implementation.

---

## 🎥 Demonstration

A gameplay demonstration is included in the repository:

**`test.mp4`**

The video demonstrates the current state of the playable prototype and its gameplay systems.

---

## 🚧 Development Status

This project is **actively being developed**.

The current version focuses on establishing a solid gameplay and AI foundation. Future development will concentrate on improving the enemy decision-making architecture and introducing more adaptive AI techniques.

---

## 👩‍💻 Author

**Parya Famil Khodaei**

Bachelor's Degree in Electrical Engineering

### Interests

- Game Artificial Intelligence
- Machine Learning
- Reinforcement Learning
- Intelligent Agents
- Computer Vision
- Gameplay Programming
- AI-driven Game Development

