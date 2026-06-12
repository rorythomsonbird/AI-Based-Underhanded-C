# AI-Based Underhanded C (2023-2024)

## Overview

This project explores the emerging risk of **AI-generated underhanded code**, specifically within the context of the C programming language. It accompanies a research report investigating how large language models (LLMs) can be prompted—intentionally or unintentionally—to produce code that appears correct but contains subtle, malicious, or deceptive behavior.

The goal is not to weaponize these techniques, but to **understand, demonstrate, and ultimately mitigate them**.

---

## Motivation

As LLMs become integrated into development workflows, they are increasingly trusted to generate production code. However, recent research has shown that these systems can:

* Produce **plausible but insecure implementations**
* Embed **hidden logic flaws or vulnerabilities**
* Be manipulated via **prompt injection or adversarial inputs**
* Contribute to the spread of harmful patterns across codebases

This mirrors broader concerns in AI security, where adversarial inputs can propagate across systems—similar to how self-replicating prompt attacks have been demonstrated in modern AI ecosystems .

---

## What is “Underhanded Code”?

Underhanded code is software that is intentionally written to appear legitimate while concealing malicious intent. In C, this can include:

* Subtle memory corruption or undefined behavior
* Logic bombs or hidden conditional triggers
* Misleading naming or structure to obscure intent
* Exploiting edge cases in low-level operations

This project examines how AI systems can unknowingly (or under adversarial prompting) generate such patterns.

---

## Project Scope

This repository supports the report through:

* **Example code samples** demonstrating underhanded techniques
* **AI-generated outputs** showing how models can produce deceptive implementations
* **Analysis of vulnerabilities** introduced by AI-generated code
* **Detection approaches** for identifying suspicious patterns

---

## Key Findings

From the accompanying report:

* AI-generated code can **pass surface-level review** while containing deeper issues
* Prompt phrasing significantly influences whether unsafe code is produced
* Traditional static analysis may miss **contextual or intent-based vulnerabilities**
* There is a growing need for **AI-aware security tooling**

---

## Defensive Insights

To mitigate these risks, the report highlights several approaches:

* Treat AI-generated code as **untrusted input**
* Apply **multi-layer validation** (static + semantic analysis)
* Use **prompt hardening and input sanitization**
* Introduce **runtime enforcement and monitoring**

Modern tools are beginning to move in this direction by enforcing security at runtime rather than relying solely on prompts or pre-checks .

---

## Limitations

* This project focuses on **demonstration and analysis**, not exhaustive detection
* Examples are intentionally simplified to highlight specific techniques
* Results may vary across different models and configurations

---

## Future Work

* Automated detection of underhanded patterns in AI-generated code
* Integration with secure coding pipelines
* Expansion beyond C to other languages (e.g., Python, Rust)
* Combining static and LLM-based analysis for deeper inspection

---

## Disclaimer

This project is intended for **educational and research purposes only**. The techniques discussed are meant to improve understanding of AI security risks and should not be used for malicious purposes.

---

## Related Work

* Prompt injection and adversarial AI research
* AI-assisted code generation security
* Static and dynamic analysis tools for low-level languages

---

## Author

Rory Thomson Bird

---

## Tool Use Instructions

Firstly ensure python is installed.

Enter the following commands into the command line:
pip install openai==0.28
pip install tk
pip install setuptools
pip install flask requests
pip install selenium
pip install chromedriver-py
pip install --upgrade google-api-python-client google-auth-httplib2 google-auth-oauthlib

Ensure that gcc is installed and prepared for use.
If the pip install tk command does not install tkinter, this will need to be installed manually.
If using Linux(Highly unrecommended) use sudo apt install python3-tk

If the unlikely error that may appear on some machines of "Cannot find 'Samples' path" occurs then all mentions of the path "Samples" will need to be replaced with the full directory path.

This program should be run from a Windows machine for optimal use. The program should run on every platform but may appear poor, visually.

After these modules are installed, run from GUI.py
