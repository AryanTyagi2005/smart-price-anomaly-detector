# 💡 Smart Price Anomaly Detector

A hybrid C++ and Python (Streamlit) project that detects unusual product prices to prevent costly errors in online stores.

---

## 🚀 Problem

Sometimes, products on shopping websites get incorrect prices like:

- 🧼 A soap priced at ₹999  
- 📺 A TV listed at ₹10  

This causes:
- Confused customers
- Financial loss
- Fraud opportunities

---

## ✅ Our Solution

We built a **Smart Price Anomaly Detector** that:

- Reads product prices from a CSV file
- Detects “weird” or abnormal prices using statistical methods
- Highlights suspicious prices for review
- Shows results in a visual, user-friendly dashboard

---

## 🛠 Tech Stack

| Component | Tech |
|----------|------|
| Backend | C++ |
| Frontend | Python (Streamlit) |
| Data Input | CSV file |
| Detection Logic | Z-score, Mean, Std Deviation |

---

## 🧩 Project Structure

```bash
smart-price-anomaly-detector/
├── anomaly_detector.cpp/          # Handles data parsing + anomaly logic
├── app.py/   # Web UI using Streamlit
├── README.md
└── LICENSE
