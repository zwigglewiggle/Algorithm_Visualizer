# Projektplan: Algorithm Visualizer in C++

## Zielbild
Das Projekt entwickelt sich zu einer modularen Visualisierungsplattform für Algorithmen. Der aktuelle Fokus liegt auf einem **stabilen Kern** mit klarer Trennung zwischen:
- Algorithmusberechnung
- Playback / Timeline
- Darstellung
- UI-Steuerung

## Aktuelles Release-Ziel
Das derzeit umgesetzte Release ist ein **Terminal-MVP mit hochwertiger Darstellung**. Ziel ist nicht maximale Feature-Menge, sondern ein sauberer, demonstrierbarer Stand mit solider Erweiterungsbasis.

## Enthalten im aktuellen MVP
- Bubble Sort als Referenzalgorithmus
- vollständige Snapshot-Timeline pro Schritt
- Datengenerierung über mehrere Presets
- Playback mit Start, Pause, Reset und Fortschrittsverwaltung
- modernes Dashboard-Rendering im Terminal
- kleine automatische Tests für Kernbereiche

## Nächste Projektphase
Die nächste sinnvolle Phase ist ein grafisches Frontend auf Basis der bestehenden Kernlogik. Dafür bleibt die aktuelle Architektur bewusst render-agnostisch.

## Technische Leitlinien
- C++20 und CMake bleiben die Basis.
- Neue Algorithmen sollen `AlgorithmStep`-kompatibel arbeiten.
- UI und Rendering dürfen keine Sortierlogik duplizieren.
- Dokumentation soll immer den realen Implementierungsstand widerspiegeln.
