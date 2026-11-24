<img width="4000" height="2252" alt="20261120_102649" src="https://github.com/user-attachments/assets/95f0daf5-bed6-442e-89b1-149b2c31a957" />**# DIY Cordless Soldering Fume Extractor**

<img width="4000" height="2252" alt="20261120_102043" src="https://github.com/user-attachments/assets/2d73c2b1-b6f3-4994-93a7-69ee1a2c7fd7" />
<img width="1280" height="720" alt="3" src="https://github.com/user-attachments/assets/e80b90c2-5ff6-4f42-9ce0-945070575b7c" />

### A LIGIENCE Engineering Project

A custom-designed, 3D-printed, cordless soldering fume extractor built to make my workbench safer and more practical.

This project combines mechanical design, airflow and filtration, battery management, and embedded electronics into a compact, rechargeable unit. It features a modular enclosure, replaceable filtration, adjustable fan speed, an OLED display, and a rechargeable 18650 battery system.

What started as a simple idea to deal with soldering fumes eventually turned into a much more involved engineering project. From designing the enclosure and electronics to troubleshooting, assembly, and testing, this repository documents the entire build.

This repository contains the Arduino firmware, circuit schematic, 3D models, and other project resources.

**[WATCH THE BUILD & ASSEMBLY VIDEO](https://youtu.be/5IX9ubYjiIw)**

---

**## 📌 Project Overview**

After almost 10 years of soldering, I finally got around to doing something about the fumes I've been putting up with.

Rather than purchasing a conventional fume extractor, I decided to design and build my own. I wanted something cordless, rechargeable, easy to maintain, and adaptable enough to accommodate future modifications.

The result is a custom-built soldering fume extractor featuring a 3D-printed enclosure, a replaceable filtration assembly, adjustable fan speed, and an integrated electronic control system.

The electronics are built around an Arduino Nano, which reads a potentiometer input and controls the fan through PWM using an IRLB8721 MOSFET. An OLED display provides feedback on the current PWM setting.

The power system uses three 18650 lithium-ion cells connected in parallel in a 1S3P configuration. A charging and discharging module, battery protection circuitry, and a boost converter provide the power required by the system.

**### Main Features**

- **Cordless operation:** Powered by three rechargeable 18650 lithium-ion cells.
- **Modular enclosure:** Designed for easier assembly, maintenance, and future modifications.
- **Replaceable filtration:** Uses HEPA filter material and activated carbon.
- **Adjustable fan speed:** Manual PWM control through a potentiometer.
- **OLED display:** Displays the current fan PWM percentage.
- **USB-C charging:** Rechargeable through a Type-C charging interface.
- **Modular fan support:** Designed to accommodate different fan sizes with minimal redesign.
- **Duct accessory:** An additional attachment for experimenting with airflow direction and extraction arrangements.
- **Open-source firmware:** Arduino source code included in the repository.

---

**## 🛠️ Design & Development**

The project was developed around a few core design requirements.

### 1. Mechanical Design

The enclosure was designed in Fusion 360 and manufactured using 3D printing.

I wanted the design to be practical without sacrificing its appearance or making maintenance unnecessarily complicated.

The main design considerations included:

- Compact workbench footprint.
- Easy access to the filtration assembly.
- Replaceable filter arrangement.
- Modular fan mounting system.
- Simple assembly and disassembly.
- Adjustable positioning of the filter assembly.
- Compatibility with different fan sizes.

The enclosure uses a support arrangement that allows the filtration section to be positioned relative to the workbench.

The modular approach also makes it easier to experiment with different fan configurations without having to redesign the entire enclosure.

### 2. Airflow & Filtration

The filtration system combines two types of filter media:

| Filter | Purpose |
|---|---|
| HEPA filter material | Intended to capture fine airborne particles |
| Activated carbon filter | Intended to adsorb gases and odours |

The fan draws air through the filtration assembly, allowing the filter media to process the incoming air.

The project also includes a separate duct accessory for experimenting with alternative airflow arrangements and directing extraction away from the immediate work area.

One of the challenges encountered during development was balancing airflow, filter resistance, and fan performance.

The initial fan configuration did not provide the performance I wanted, so a higher-speed 90 mm fan was ordered for further testing.

The modular design makes it possible to test this improvement without having to redesign the entire extractor.

### 3. Electronics & Control System

The electronics are built around an Arduino Nano.

The Arduino reads the position of the potentiometer and converts it into a PWM output used to control the fan through an IRLB8721 MOSFET.

The OLED display provides feedback on the current PWM setting, allowing the fan speed to be adjusted manually.

The main electronic functions include:

- Arduino-based control.
- PWM fan speed adjustment.
- OLED status display.
- USB-C charging.
- Battery protection and management.
- Boosted 12 V supply for the fan.

---

## 🔌 Circuit Design & Electronics

The electronics are divided into three main sections.

### Battery & Charging System

The extractor uses three 18650 lithium-ion cells connected in parallel.

**Battery configuration: 1S3P**

- 1 series group.
- 3 cells connected in parallel.
- 1S BMS for battery protection.
- MH-CD42 charging/discharging module.
- USB-C charging interface.

### Fan Power System

The XL6009 boost converter steps up the battery supply to 12 V for the cooling fan.

The IRLB8721 MOSFET handles the fan's PWM switching, allowing the Arduino Nano to regulate its speed.

### User Interface & Control

The potentiometer provides the manual speed-control input.

The Arduino reads the potentiometer position, adjusts the PWM output, and updates the OLED display with the current PWM percentage.

---

## 🧰 Components List

### Microcontroller & Display

| Component | Quantity | Description |
|---|---:|---|
| Arduino Nano | 1 | Main microcontroller |
| 0.96-inch OLED Display | 1 | Displays fan PWM percentage |
| 10 kΩ Potentiometer | 1 | Manual fan speed adjustment |

### Fan & Control

| Component | Quantity | Description |
|---|---:|---|
| 80/90 mm PC Cooling Fan | 1 | Main airflow source |
| IRLB8721 MOSFET | 1 | PWM fan switching |
| Resistors | As required | MOSFET control circuitry |
| 2-pin PCB Terminal | 1 | Fan connection |

### Power System

| Component | Quantity | Description |
|---|---:|---|
| 18650 Lithium-ion Cells | 3 | Parallel battery configuration (1S3P) |
| 1S BMS | 1 | Battery protection |
| MH-CD42 Module | 1 | Charging and discharging |
| USB-C Port | 1 | Charging interface |
| XL6009 Boost Converter | 1 | Boosted 12 V fan supply |
| SPST Switch | 1 | Main power switching |

### Mechanical & Filtration

| Component | Description |
|---|---|
| 3D-Printed Enclosure | Custom-designed housing |
| HEPA Filter Material | Particle filtration media |
| Activated Carbon Filter | Carbon filtration media |
| Filter Supports | Filter retention and assembly |
| Fasteners | Mechanical assembly |
| Flexible Ducting | Optional airflow direction accessory |

---

## 🖥️ Firmware & Software

The Arduino Nano firmware is included in this repository.

The firmware handles the control and user interface functions of the extractor.

### Main Functions

- Reading the potentiometer input.
- Mapping the potentiometer position to a PWM output.
- Controlling the fan through the MOSFET.
- Updating the OLED display.
- Displaying the current PWM percentage.

**Microcontroller:** Arduino Nano

**Development Environment:** Arduino IDE

The source code can be downloaded, modified, and uploaded to the Arduino Nano.

---

## 🖼️ Project Visuals

### Final Build

![Soldering Fume Extractor - Front View](<img width="4000" height="2252" alt="20261120_102043" src="https://github.com/user-attachments/assets/005ca151-dff2-48dc-be8d-f59eec0161ac" />
)

![Soldering Fume Extractor - Workbench Setup](<img width="4000" height="2252" alt="20261120_102649" src="https://github.com/user-attachments/assets/c32a6890-54a9-41f5-b98a-10aab6bde420" />
)

### Duct Accessory

![Fume Extractor with Duct Accessory](<img width="4000" height="2252" alt="20261120_102116" src="https://github.com/user-attachments/assets/b63b0cf3-a509-4954-8409-f290c6ea73a5" />
)

### Circuit Schematic

![Fume Extractor Circuit Schematic](
)

### 3D Model & Mechanical Design

![Fume Extractor Fusion 360 Model](<img width="1699" height="1061" alt="in fusion image" src="https://github.com/user-attachments/assets/797f388c-490d-4b84-8425-a70db73c59ad" />
)

---

## 🧪 Assembly & Build Guide

The complete YouTube build video also serves as the visual assembly guide for this project.

It covers the design process, 3D printing, electronics, troubleshooting, assembly, and testing.

**[WATCH THE FULL BUILD & ASSEMBLY GUIDE](https://youtu.be/5IX9ubYjiIw)**

---

## 🧰 Tools & Technologies

| Tool | Application |
|---|---|
| Fusion 360 | Mechanical design and 3D modelling |
| Arduino IDE | Microcontroller programming |
| Fritzing | Circuit schematic design |
| 3D Printer | Enclosure and mechanical components |

### Engineering Concepts

- **PWM Control:** Regulating fan speed through pulse-width modulation.
- **MOSFET Switching:** Electronic control of the fan's power.
- **Battery Management:** Charging, discharging, and protecting a lithium-ion battery pack.
- **DC-DC Boost Conversion:** Increasing the battery voltage to the fan's required supply voltage.
- **Modular Mechanical Design:** Designing interchangeable components for easier modifications.
- **Airflow & Filtration:** Balancing fan performance and filter resistance.

---

## 🚧 Known Issues & Future Improvements

The project is a functional prototype, but there are still areas I want to improve.

- [ ] Test the higher-speed 90 mm fan.
- [ ] Improve airflow and overall extraction performance.
- [ ] Refine the filter arrangement and airflow sealing.
- [ ] Further optimise the duct accessory.
- [ ] Improve modular compatibility with different fan sizes.
- [ ] Refine the enclosure and assembly details.
- [ ] Conduct more extensive testing of the filtration arrangement.

---

## 🤝 Support & Community

If you enjoy my projects and would like to support future engineering builds, consider joining the LIGIENCE community.

### Patreon

Support future projects and get access to exclusive content, behind-the-scenes footage, and upgraded project files.

https://patreon.com/LIGIENCE

### Discord Builders Community

Connect with other makers, share your projects, ask questions, exchange ideas, and learn from other builders.

https://discord.gg/wWsgzk3ky

---

## 📜 License

This project is licensed under the **MIT License**.

You are free to use, copy, modify, merge, publish, distribute, sublicense, and sell copies of the software, subject to the conditions of the MIT License.

See the [LICENSE](LICENSE) file for the full licence text.

---

**A LIGIENCE Engineering Project**

Designing, building, testing, and learning through real-world engineering projects.
