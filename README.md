# Scientific Data Analysis Framework

A highly modular, plugin-based scientific data analysis framework designed to handle varied data formats and execute dynamic analysis pipelines. The system decouples data ingestion, core orchestrations, and analytical algorithms through an easily extensible shared library configuration.

## 🚀 System Architecture Overview

The system is split into distinct, isolated operational layers to maximize maintainability and scalability:

* **Application (`app`)**: The orchestration entry point, currently managing console execution with native support for future Qt GUI abstractions.
* **Framework Core (`framework`)**: The backbone of the ecosystem. It manages structural configurations, provides centralized logging mechanics, orchestrates runtime workflows, and manages the operational lifecycle of plugins.
* **Data Module (`framework/Data`)**: Provides a unified data abstraction format (`DataSet`) independent of file layouts, built dynamically by custom data loaders.
* **Plugins (`plugins`)**: Isolated analytical extensions compiled as separate shared libraries (`.dll` / `.so`), discovered dynamically during runtime configuration.

---

## 🛠️ Key Features

### 1. Unified Ingestion Layer
* **Format-Independent Data Extraction:** Abstract data loaders parse target source structures into a universal `DataSet` model containing columns, rows, and rich metadata.
* **Pre-bundled Modules:** Native support for **CSV** and **LAS** parsing protocols, with an open blueprint layout for future format extensions.

### 2. Dynamically Discovered Extensibility
* **Plugin-Based Infrastructure:** Analytical engines run isolated from core logic via standalone shared objects.
* **Dynamic Lifecycle Management:** The `PluginManager` dynamically searches, registers, registers runtime footprints, and unloads compiled extensions automatically.
* **Pre-implemented Algorithms:** Built-in calculation modules for Basic Descriptive Statistics (Mean, Median, Standard Deviation, Ranges), Multi-Variable Regression Profiles, and Fast Fourier Transform (FFT) signal processing algorithms.

### 3. Configurable Environment Rules
* Startup engine operations adapt instantly through a flexible external JSON structure mapping target directories, operational parameters, and system logging granularity filters (`INFO`, `WARN`, `ERROR`).

---

## ⚙️ Getting Started

### Prerequisites
* A C++17 compliant compiler (`gcc`, `clang`, or MSVC)
* CMake (Version 3.15 or higher)

### Configuration Template
Before running the application, provide a local `config.json` configuration file at startup:

```json
{
  "plugin_directory": "./plugins",
  "log_level": "INFO",
  "...": "..."
}
```

### Installation & Build Setup
1. **Clone the repository:**
   ```bash
   git clone https://github.com
   cd scientific-data-analysis-framework
   ```
2. **Generate the build system and compile:**
   ```bash
   mkdir build && cd build
   cmake ..
   cmake --build .
   ```

---

## 🧩 Developing Custom Plugins

To write custom calculation or data-loading plugins, inherit from the framework's native interface blueprints located in `framework/core/Interfaces`:

* **`IAlgorithm`**: Implement this interface to introduce custom computational tools (e.g., Machine Learning, Custom Domain Analytics).
* **`IDataLoader`**: Implement this interface to expand support for custom file extensions or proprietary data layouts.

---

## 📄 License

This project is licensed under the MIT License - see the `LICENSE` file for details.
