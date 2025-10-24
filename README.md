# 📚 AlgoChronicle: Daily DSA Solutions & Automation Source

This repository contains the source code, metadata, and solutions for my daily Data Structures and Algorithms (DSA) practice.

It is the raw data engine that powers the **[AlgoChronicle live progress website](https://algochronicle.vercel.app/)** through an automated **"push-to-publish"** workflow.

## 🚀 Live Progress & Stats

My daily activity, streak, and spaced repetition revision schedule are automatically logged and displayed live.

| Metric                | Status                | Link                                                                       |
| :-------------------- | :-------------------- | :------------------------------------------------------------------------- |
| **Current Streak**    | **Live Data**         | [View Consistency Dashboard](https://algochronicle.vercel.app/consistency) |
| **Revision Schedule** | **Spaced Repetition** | [View Revisions Due](https://algochronicle.vercel.app/revisions)           |
| **All Logs**          | **Chronological**     | [View All Logs](https://algochronicle.vercel.app/)                         |

---

## ⚙️ Repository Structure

Each problem solved resides in a dedicated folder named with the format `dayXXX_problem_name/`. This highly structured format is key to the automation pipeline.
└── 📁day001_two_sum ├── README.md # <--- SOURCE OF TRUTH (Metadata & Problem Statement) ├── solution.cpp ├── solution.java └── solution.py └── 📁day002_add_two_numbers ├── README.md └── optimized.py

### 📋 Problem Folder Content

Each folder is guaranteed to contain a `README.md` and one or more solution files that the system parses:

| File Type            | Purpose                                                                                                | Example                   |
| :------------------- | :----------------------------------------------------------------------------------------------------- | :------------------------ |
| **`README.md`**      | **Metadata Source:** Defines problem details (`Title`, `Complexity`, `Pattern`, etc.) for the website. | **Pattern:** `Hash Table` |
| **`optimized.py`**   | **Primary Solution:** The most efficient approach I developed.                                         | `solution.cpp`            |
| **`brute_force.py`** | **Alternative Solution:** Used for comparison and complexity analysis.                                 | `solution.java`           |

---

## 🧠 AlgoChronicle Automation Pipeline

This project demonstrates a fully automated CI/CD workflow built on the principle: **Commit Code $\rightarrow$ Update Database $\rightarrow$ Publish Website.**

1.  **Trigger:** A `git push` to the `main` branch fires a **GitHub Webhook**.
2.  **Process:** The webhook sends the payload to a Next.js API route (`/api/github-webhook`). The server script automatically:
    - Detects new or modified `dayXXX_*` folders.
    - Fetches the raw file contents (`README.md` and solutions) from the repo.
    - Parses the essential metadata (complexity, pattern, link).
3.  **Publish:** The structured data is committed to the **Firebase Firestore** database. The AlgoChronicle website fetches this data live, ensuring the progress reflects the latest commit instantly.

---

## 🤝 Contribution & Engagement

This repository is primarily my personal development journal, but I welcome feedback!

- **Spot a better approach or optimization?** Feel free to open a discussion or a pull request.
- **Interested in the tech stack?** Check out the main Next.js repository (not linked here, but used for deployment) to see how the system is built.

---

**Happy Coding!**
