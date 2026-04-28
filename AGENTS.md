# AGENTS.md

This file defines the workflow and conventions for AI agents operating in this repository.

---

## Skill System

Project-level reusable skills are stored in `.agents/skills/`.  
Each skill lives in its own subdirectory: `.agents/skills/<skill-name>/`  
Every skill directory **must** contain a `SKILL.md` as its main entry point.  
Supporting scripts, templates, or resource files are placed alongside `SKILL.md` in the same directory.

### SKILL.md format

```
# <Skill Name>

## Purpose
One-sentence description of what this skill does.

## Usage
How to invoke or apply this skill (commands, inputs, outputs).

## Files
List any supporting files in this directory and their roles.

## Source
Where this skill came from (URL, repo, or "custom").
```

---

## Agent Workflow

When receiving any task, follow these steps in order:

1. **Check local skills first** — scan `.agents/skills/` for an existing skill that covers the task.
2. **Search externally if needed** — if no local skill fits, search GitHub open-source repositories and [Skills.sh](https://skills.sh) for a relevant skill.
3. **Prefer quality sources** — choose skills with clear provenance, standard structure, complete documentation, and low risk.
4. **Install by saving locally** — store the adopted skill under `.agents/skills/<skill-name>/` with a proper `SKILL.md`.
5. **Update documentation** — after installing, ensure `SKILL.md` is complete so future sessions can reuse the skill without re-searching.
6. **Fall back to custom implementation** — if no suitable skill exists anywhere, complete the task manually, then distill the solution into a new skill under `.agents/skills/` for future reuse.
7. **Avoid duplication** — never reinstall a skill that already exists locally; keep the skills directory tidy, with clear names and consistent structure.

---

## Conventions

- Rules here are intentionally concise and practical — update them as the workspace evolves.
- Prioritize **long-term reusability** over one-off task completion.
- This repository is designed to grow into a self-extending personal AI workspace (OpenClaw style).
