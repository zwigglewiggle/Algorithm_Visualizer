# MVP-Umsetzungsreihenfolge für Woche 1–2

## Ziel des MVP nach Woche 2

Nach zwei Wochen soll euer Projekt bereits folgendes können:

- ein Fenster öffnen
- einen stabilen Hauptloop besitzen
- ein Array als Balkendiagramm darstellen
- einen einfachen Playback-Mechanismus besitzen
- Bubble Sort als ersten echten Algorithmus visualisieren
- über eine minimale UI steuerbar sein
- so strukturiert sein, dass später weitere Algorithmen leicht ergänzt werden können

Der Fokus liegt also nicht auf "möglichst vielen Features", sondern auf einem **sauberen Kern**, den ihr später erweitern könnt.

---

## Woche 1 – Fundament bauen

### Tag 1: Projektgerüst und Build-System

### Ziel
Ein sauberes C++-Projekt mit CMake, Git und der finalen Ordnerstruktur anlegen.

### Aufgaben

1. Projektordner anlegen
2. Git initialisieren
3. CMake-Grundgerüst anlegen
4. Quellordner und Dokumentationsordner erstellen
5. `README.md`, `.gitignore`, `CMakeLists.txt` anlegen
6. leere Quelldateien für App, Core, Rendering, Playback und Algorithmen erzeugen

### Ergebnis am Ende des Tages

- das Projekt kompiliert
- es existiert mindestens ein ausführbares Target
- `main.cpp` baut erfolgreich

---

### Tag 2: Anwendungsgrundgerüst

### Ziel
Die Anwendung soll ein Fenster öffnen und einen einfachen Event-/Renderloop besitzen.

### Aufgaben

1. `Application`-Klasse anlegen
2. Fenstererzeugung in die App-Schicht verschieben
3. Event-Verarbeitung kapseln
4. `run()`-Methode mit Hauptloop einführen
5. `update()` und `render()` logisch trennen

### Ergebnis am Ende des Tages

- Fenster startet korrekt
- Fenster lässt sich sauber schließen
- Hintergrund wird gezeichnet
- Grundstruktur für weiteren Ausbau steht

### Betroffene Dateien

- `src/main.cpp`
- `src/app/Application.hpp`
- `src/app/Application.cpp`
- `src/app/AppState.hpp`
- `src/app/AppState.cpp`

---

### Tag 3: AppState und zentrale Datentypen

### Ziel
Die wichtigsten Zustände und Datenstrukturen definieren.

### Aufgaben

1. `AppState` mit den globalen UI-/Playback-/Algorithmus-Zuständen entwerfen
2. Grundlegende Typen für Algorithmen und Playback anlegen
3. erste Enums definieren

### Benötigte Typen

- `PlaybackState`
- `AlgorithmCategory`
- `StepType`
- `StatusCode`

### Ergebnis am Ende des Tages

- zentrale Zustände sind nicht mehr "implizit" im Code verteilt
- der Code bekommt eine stabile Struktur

### Betroffene Dateien

- `src/core/Types.hpp`
- `src/core/Result.hpp`
- `src/app/AppState.hpp`
- `src/app/AppState.cpp`
- `src/algorithms/common/AlgorithmStep.hpp`
- `src/algorithms/common/Metrics.hpp`
- `src/algorithms/common/DataSet.hpp`

---

### Tag 4: Datensatzmodell und Dummy-Daten

### Ziel
Ein Datensatzmodell definieren und testweise ein Array visualisieren können.

### Aufgaben

1. `DataSet` modellieren
2. zufällige Array-Daten erzeugen
3. einfache Presets vorsehen
4. feste Testdaten und Zufallsdaten unterstützen

### Verantwortlichkeiten von `DataSet`

- Werte speichern
- Größe liefern
- Zugriff auf Werte ermöglichen
- optional Ursprungszustand merken

### Ergebnis am Ende des Tages

- ein Array kann erzeugt werden
- Daten können an Rendering oder Playback übergeben werden

### Betroffene Dateien

- `src/algorithms/common/DataSet.hpp`
- `src/data/DataGenerator.hpp`
- `src/data/DataGenerator.cpp`
- `src/data/Presets.hpp`
- `src/data/Presets.cpp`

---

### Tag 5: Erste Array-Visualisierung

### Ziel
Ein Array als Balkendiagramm darstellen.

### Aufgaben

1. `ArrayView` anlegen
2. Werte auf Bildschirmkoordinaten abbilden
3. Balkenhöhe aus Zahlenwerten berechnen
4. Basisfarben definieren
5. Rendering von Texten vorbereiten

### Darstellungsregeln

- kleine Werte = niedrige Balken
- große Werte = hohe Balken
- alle Balken zunächst in neutraler Farbe
- sauberer Rand, einheitiger Abstand, modernes Layout

### Ergebnis am Ende des Tages

- zufällige Arrays werden sichtbar dargestellt
- Fenster enthält bereits eine brauchbare Hauptansicht

### Betroffene Dateien

- `src/rendering/Renderer.hpp`
- `src/rendering/Renderer.cpp`
- `src/rendering/views/ArrayView.hpp`
- `src/rendering/views/ArrayView.cpp`
- `src/rendering/ColorPalette.hpp`
- `src/rendering/Theme.hpp`

---

## Woche 2 – Playback, Bubble Sort und minimale UI

### Tag 6: Step-Modell einführen

### Ziel
Zustandsänderungen eines Algorithmus als explizite Schritte modellieren.

### Aufgaben

1. `AlgorithmStep` fertig definieren
2. zunächst nur für Sortierung relevante Step-Typen unterstützen
3. Metriken mitführen

### Sinnvolle Step-Typen für das MVP

- `Compare`
- `Swap`
- `Write`
- `MarkSorted`
- `Done`

### Ergebnis am Ende des Tages

- es gibt ein standardisiertes Format für Algorithmusereignisse
- Playback und Rendering können darauf aufbauen

### Betroffene Dateien

- `src/algorithms/common/AlgorithmStep.hpp`
- `src/algorithms/common/Metrics.hpp`
- `src/core/Types.hpp`

---

### Tag 7: PlaybackController bauen

### Ziel
Eine gespeicherte Liste von Schritten abspielen können.

### Aufgaben

1. `PlaybackController` entwerfen
2. aktuelle Position in der Timeline verwalten
3. `play`, `pause`, `reset`, `stepForward` einführen
4. aktuelle Wiedergabegeschwindigkeit verwalten
5. aktuellen Snapshot oder Zustand bereitstellen

### Ergebnis am Ende des Tages

- auch ohne echten Algorithmus kann eine Liste von Dummy-Schritten abgespielt werden
- die Architektur ist jetzt entkoppelt

### Betroffene Dateien

- `src/playback/PlaybackController.hpp`
- `src/playback/PlaybackController.cpp`
- `src/playback/Timeline.hpp`
- `src/playback/Timeline.cpp`

---

### Tag 8: Bubble Sort als Referenzalgorithmus

### Ziel
Den ersten Algorithmus sauber in das System integrieren.

### Aufgaben

1. `Algorithm`-Basisschnittstelle definieren
2. `BubbleSort`-Klasse anlegen
3. beim Lauf `AlgorithmStep`s erzeugen
4. `Metrics` aktualisieren
5. `AlgorithmResult` zurückgeben

### Bubble-Sort-MVP soll erzeugen

- Vergleichsschritte
- Tauschschritte
- Markierungen für final sortierte Elemente
- Abschlusszustand

### Ergebnis am Ende des Tages

- Bubble Sort läuft
- Bubble Sort liefert Schrittinformationen statt direkt zu rendern

### Betroffene Dateien

- `src/algorithms/common/Algorithm.hpp`
- `src/algorithms/common/AlgorithmContext.hpp`
- `src/algorithms/common/AlgorithmStep.hpp`
- `src/algorithms/sorting/BubbleSort.hpp`
- optional später `BubbleSort.cpp`

---

### Tag 9: Bubble Sort mit ArrayView koppeln

### Ziel
Die erzeugten Steps sichtbar machen.

### Aufgaben

1. `PlaybackController` mit `ArrayView` koppeln
2. bei `Compare` andere Farbe anzeigen
3. bei `Swap` Elemente optisch hervorheben
4. bei `MarkSorted` finalen Zustand farblich markieren

### Ergebnis am Ende des Tages

- der erste echte Algorithmus ist visuell nachvollziehbar
- ihr habt ein echtes End-to-End-MVP

---

### Tag 10: Minimale UI

### Ziel
Das Projekt soll steuerbar werden.

### Aufgaben

1. einfache UI integrieren
2. Buttons für Start/Pause/Reset
3. Slider für Geschwindigkeit
4. Button für neue Daten
5. Metriken anzeigen

### Minimale Controls

- Start
- Pause
- Reset
- Step Forward
- Randomize
- Größe
- Geschwindigkeit

### Ergebnis am Ende des Tages

- die Anwendung ist bereits vorzeigbar
- ein Nutzer kann den Ablauf verstehen und beeinflussen

### Betroffene Dateien

- `src/ui/UiManager.hpp`
- `src/ui/UiManager.cpp`
- `src/ui/panels/ControlPanel.hpp`
- `src/ui/panels/MetricsPanel.hpp`
- `src/ui/panels/AlgorithmPanel.hpp`

---

## Klassendiagramm auf Textbasis

```text
+-------------------+
| Application       |
+-------------------+
| - appState        |
| - renderer        |
| - uiManager       |
| - playback        |
+-------------------+
| + run()           |
| + update()        |
| + render()        |
+---------+---------+
          |
          v
+-------------------+
| AppState          |
+-------------------+
| - selectedAlgo    |
| - playbackState   |
| - datasetSize     |
| - speed           |
| - currentStep     |
+-------------------+

+-------------------+
| Algorithm         |<------------------------------+
+-------------------+                               |
| + getName()       |                               |
| + validate()      |                               |
| + run()           |                               |
+-------------------+                               |
                                                    |
                                         +-------------------+
                                         | BubbleSort        |
                                         +-------------------+
                                         | + run()           |
                                         +-------------------+

+-------------------+
| AlgorithmResult   |
+-------------------+
| - finalData       |
| - steps           |
| - metrics         |
| - status          |
+-------------------+

+-------------------+
| AlgorithmStep     |
+-------------------+
| - type            |
| - indices         |
| - values          |
| - metrics         |
+-------------------+

+-------------------+
| PlaybackController|
+-------------------+
| - steps           |
| - currentIndex    |
| - speed           |
| - state           |
+-------------------+
| + load()          |
| + play()          |
| + pause()         |
| + reset()         |
| + stepForward()   |
| + getSnapshot()   |
+---------+---------+
          |
          v
+-------------------+
| ArrayView         |
+-------------------+
| + render()        |
| + setSnapshot()   |
+-------------------+

+-------------------+
| Renderer          |
+-------------------+
| + beginFrame()    |
| + drawArrayView() |
| + endFrame()      |
+-------------------+

+-------------------+
| UiManager         |
+-------------------+
| + render()        |
| + collectActions()|
+-------------------+