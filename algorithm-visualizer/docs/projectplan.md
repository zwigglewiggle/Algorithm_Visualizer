# Projektplan: Algorithmus-Visualisierer in C++

## 1. Ziel des Projekts

Ihr baut einen **interaktiven Algorithmus-Visualisierer** in C++, der klassische Algorithmen nicht nur korrekt ausführt, sondern ihre Zustandsänderungen **frameweise sichtbar** macht. Das Projekt soll dabei ausdrücklich **portfolio-tauglich** sein: also technisch sauber strukturiert, modular erweitertbar und visuell modern.

Das Kernziel ist nicht „nur ein paar Balken zu sortieren“, sondern eine kleine Visualisierungsplattform mit drei klar getrennten Bereichen:

1. **Algorithmik-Ebene** – Algorithmen erzeugen nachvollziehbare Zustandsänderungen.
2. **Visualisierungs-Ebene** – diese Zustandsänderungen werden animiert dargestellt.
3. **UI-/Steuerungs-Ebene** – Nutzer können Daten generieren, Parameter ändern, pausieren, weiterschalten und Algorithmen vergleichen.

---

## 2. Empfohlener Technologie-Stack

### Empfohlene Hauptkombination

Für ein Übungs- und Portfolio-Projekt in C++ würde ich euch folgende Kombination empfehlen:

- **C++20** als Programmiersprache
- **CMake** als Build-System
- **SFML 3** für Fenster, Rendering, Text, Shapes und Eingaben
- **Dear ImGui** für moderne Debug-/Tool-UI, Panels, Slider, Buttons, Docking
- optional **ImPlot** für Diagramme/Statistiken
- optional **nlohmann/json** für Konfigurationsdateien und Presets
- optional **spdlog** für Logging
- optional **doctest** oder **Catch2** für Tests

Diese Auswahl ist sinnvoll, weil SFML 3 aktuell als Multimedia-/Rendering-Bibliothek dokumentiert wird und weiterhin die Module **system, window, graphics, audio, network** anbietet. Die SFML-Dokumentation empfiehlt außerdem den Einstieg über ein **CMake-Template**. Dear ImGui ist sehr verbreitet für Tools und Editor-artige Interfaces; die offizielle Dokumentation empfiehlt für Docking explizit den **docking branch**, der als gut gepflegt und für Docking/Multi-Viewport geeignet beschrieben wird. :contentReference[oaicite:0]{index=0}

### Warum nicht direkt Qt?

**Qt 6** ist stark, wenn ihr eher eine klassische Desktop-App oder eine QML-basierte App mit vielen Standard-UI-Komponenten bauen wollt. Qt Widgets und Qt Quick/QML sind offiziell beide sehr gut dokumentiert. Für einen „algorithm visualizer“ mit eher spiel-/editorartigem Look ist SFML + Dear ImGui aber meist direkter, leichtergewichtig und flexibler. Qt wäre die bessere Wahl, wenn euer Fokus auf Enterprise-Desktop-UI statt auf „cooles animiertes Rendering“ liegt. :contentReference[oaicite:1]{index=1}

### Warum nicht raylib als Standardempfehlung?

**raylib** ist ebenfalls sehr gut für Lern- und Grafikprojekte geeignet und hat viele Beispiele sowie eine einfache API. Für ein Tool mit stärkerem Desktop-/Editor-Charakter ist die Kombination **SFML + Dear ImGui** aber in der Regel angenehmer, insbesondere wenn mehrere Panels, Konfigurationsfenster und Debug-Ansichten geplant sind. raylib bleibt trotzdem eine gute Alternative, falls ihr es minimalistischer mögt. :contentReference[oaicite:2]{index=2}

---

## 3. Funktionsumfang des ersten sinnvollen Releases

### MVP-Funktionen

Das erste Release sollte bewusst klein, aber vollständig sein:

- Visualisierung von **Sortieralgorithmen**
  - Bubble Sort
  - Insertion Sort
  - Selection Sort
  - Merge Sort
  - Quick Sort
- Darstellung eines Arrays als **Balkendiagramm**
- Zustandsänderungen Schritt für Schritt
- Steuerung über:
  - Start
  - Pause
  - Reset
  - Einzelschritt vor
  - Geschwindigkeit ändern
  - Datensatzgröße ändern
  - Zufallsdaten neu generieren
- Farbliches Hervorheben von:
  - verglichenen Elementen
  - getauschten Elementen
  - Pivot/aktuellem Index
  - bereits sortierten Bereichen
- Anzeigen von Metriken:
  - Anzahl Vergleiche
  - Anzahl Schreibzugriffe/Tausche
  - bisherige Zeit
  - aktueller Schrittindex

### Danach als Erweiterungen

- Graphalgorithmen:
  - BFS
  - DFS
  - Dijkstra
  - A*
- Datenstrukturen:
  - Heap
  - BST / AVL / Red-Black Tree
  - Union-Find
- Vergleichsmodus:
  - zwei Algorithmen auf denselben Daten parallel
- Benutzerdefinierte Datensätze
- Export von Screenshots / GIFs / Konfigurationen
- „Challenge Mode“ oder kleine Erklärtexte pro Algorithmus

---

## 4. Architekturidee

Die wichtigste Designentscheidung lautet:

**Der Algorithmus selbst darf nicht direkt rendern.**

Stattdessen erzeugt der Algorithmus **Visualisierungsereignisse** oder **Snapshots**, die vom Renderer abgespielt werden.

### Empfohlene Schichten

#### 4.1 Algorithm Layer
Verantwortlich für:
- eigentliche Algorithmuslogik
- Erzeugen von Zustandsänderungen
- Sammeln von Metriken

#### 4.2 Simulation / Playback Layer
Verantwortlich für:
- Speichern der vom Algorithmus erzeugten Schritte
- Vor-/Zurückspringen
- Pause/Resume
- Geschwindigkeitssteuerung
- Abspielen unabhängig vom eigentlichen Algorithmuslauf

#### 4.3 Visualization Layer
Verantwortlich für:
- Zeichnen von Balken, Knoten, Kanten, Texten, Hintergründen
- Farb- und Animationslogik
- Übergänge zwischen Zuständen

#### 4.4 UI Layer
Verantwortlich für:
- Menüs, Buttons, Slider, Dropdowns
- Auswahl des Algorithmus
- Anzeigen von Kennzahlen
- Theme-Umschaltung / Layout-Presets

#### 4.5 Core / App Layer
Verantwortlich für:
- Haupt-Eventloop
- Laden von Assets/Konfigurationen
- Initialisieren aller Subsysteme
- Zustandsverwaltung der gesamten Anwendung

---

## 5. Zentrales Architekturprinzip: Events oder Snapshots?

Ihr habt zwei gute Möglichkeiten.

### Variante A – vollständige Snapshots
Bei jedem Schritt speichert ihr den gesamten Zustand, z. B. das komplette Array plus Marker.

**Vorteile:**
- sehr einfach zu implementieren
- leicht debugbar
- Vor-/Zurückspringen unkompliziert

**Nachteile:**
- mehr Speicherverbrauch
- bei großen Strukturen weniger effizient

### Variante B – kleine Events / Operations
Der Algorithmus erzeugt kleine Operationen wie:
- `compare(i, j)`
- `swap(i, j)`
- `setValue(i, value)`
- `markSorted(i)`
- `setPivot(i)`

**Vorteile:**
- eleganter und speichereffizienter
- gut für Animationen
- sauber für unterschiedliche Algorithmentypen

**Nachteile:**
- komplexer in der Implementierung
- Rückwärtsnavigation schwieriger

### Empfehlung
Für euer Übungsprojekt:

- Startet bei Sortieralgorithmen mit **Snapshots** oder einer **hybriden Lösung**.
- Sobald das Grundsystem läuft, könnt ihr intern auf Events umstellen.

Eine sehr praktikable Zwischenlösung ist:
- Algorithmus erzeugt **Events**
- Playback-System baut daraus bei Bedarf **Snapshots** für die Anzeige

---

## 6. Empfohlene Projektstruktur

```text
algorithm-visualizer/
├─ CMakeLists.txt
├─ README.md
├─ docs/
│  ├─ architecture.md
│  ├─ roadmap.md
│  └─ algorithms/
│     ├─ sorting.md
│     └─ graphs.md
├─ assets/
│  ├─ fonts/
│  ├─ icons/
│  ├─ shaders/
│  └─ themes/
├─ config/
│  ├─ app_config.json
│  └─ themes.json
├─ src/
│  ├─ main.cpp
│  ├─ app/
│  │  ├─ Application.hpp
│  │  ├─ Application.cpp
│  │  ├─ AppState.hpp
│  │  └─ AppState.cpp
│  ├─ core/
│  │  ├─ Types.hpp
│  │  ├─ Result.hpp
│  │  ├─ Time.hpp
│  │  ├─ Logger.hpp
│  │  └─ Config.hpp
│  ├─ algorithms/
│  │  ├─ common/
│  │  │  ├─ Algorithm.hpp
│  │  │  ├─ AlgorithmContext.hpp
│  │  │  ├─ AlgorithmStep.hpp
│  │  │  ├─ Metrics.hpp
│  │  │  └─ DataSet.hpp
│  │  └─ sorting/
│  │     ├─ BubbleSort.hpp
│  │     ├─ InsertionSort.hpp
│  │     ├─ SelectionSort.hpp
│  │     ├─ MergeSort.hpp
│  │     └─ QuickSort.hpp
│  ├─ playback/
│  │  ├─ PlaybackController.hpp
│  │  ├─ PlaybackController.cpp
│  │  ├─ Timeline.hpp
│  │  └─ Timeline.cpp
│  ├─ rendering/
│  │  ├─ Renderer.hpp
│  │  ├─ Renderer.cpp
│  │  ├─ ColorPalette.hpp
│  │  ├─ Theme.hpp
│  │  ├─ Animation.hpp
│  │  └─ views/
│  │     ├─ ArrayView.hpp
│  │     ├─ ArrayView.cpp
│  │     ├─ GraphView.hpp
│  │     └─ GraphView.cpp
│  ├─ ui/
│  │  ├─ UiManager.hpp
│  │  ├─ UiManager.cpp
│  │  ├─ panels/
│  │  │  ├─ ControlPanel.hpp
│  │  │  ├─ MetricsPanel.hpp
│  │  │  ├─ AlgorithmPanel.hpp
│  │  │  └─ ThemePanel.hpp
│  ├─ data/
│  │  ├─ DataGenerator.hpp
│  │  ├─ DataGenerator.cpp
│  │  ├─ Presets.hpp
│  │  └─ Presets.cpp
│  ├─ utils/
│  │  ├─ Random.hpp
│  │  ├─ Math.hpp
│  │  └─ String.hpp
│  └─ tests/
│     ├─ sorting_tests.cpp
│     ├─ playback_tests.cpp
│     └─ data_tests.cpp
└─ third_party/