# Algorithm Visualizer

Ein modular aufgebauter Algorithmus-Visualisierer in C++20. Das aktuelle MVP setzt den in den Dokumentationsdateien beschriebenen Kern um: Datengenerierung, Bubble-Sort-Schrittmodell, Playback-Steuerung, Rendering-Schicht und eine minimal steuerbare Anwendung. Da in der Build-Umgebung keine SFML-Entwicklungsbibliothek verfügbar ist, nutzt das Projekt derzeit ein terminalbasiertes Renderer-MVP mit derselben Schichtenstruktur.

## Umgesetzte MVP-Bausteine
- sauberes CMake-Projekt mit wiederverwendbarer `av_core`-Bibliothek
- `AppState` für globalen Anwendungs-, Algorithmus- und Playback-Zustand
- `DataSet` und `DataGenerator` mit Presets: Random, Sorted, Reversed, Nearly Sorted, Fixed
- `BubbleSort` als Referenzalgorithmus mit expliziten `AlgorithmStep`s
- `PlaybackController` und `Timeline` für Laden, Abspielen, Pausieren, Reset und Step-Forward
- `Renderer` + `ArrayView` zur ASCII-/Terminal-Visualisierung der Array-Zustände
- minimale UI-Steuerlogik über `UiManager`
- automatisierte Tests für Daten, Sorting und Playback

## Build
```bash
cmake -S . -B build
cmake --build build
```

## Tests
```bash
ctest --test-dir build --output-on-failure
```

## Ausführen
```bash
./build/algorithm_visualizer
```

## Architekturüberblick
- **Algorithm Layer:** `src/algorithms/common`, `src/algorithms/sorting`
- **Playback Layer:** `src/playback`
- **Rendering Layer:** `src/rendering`
- **UI Layer:** `src/ui`
- **App/Core Layer:** `src/app`, `src/core`

## Nächste sinnvolle Schritte
- SFML- oder ImGui-Frontend auf die vorhandene Kernlogik setzen
- weitere Sortieralgorithmen ergänzen
- echte Benutzerinteraktion statt Demo-Playback im `Application::run()`-Loop
- Metriken pro Schritt statt nur als Gesamtergebnis verfeinern
