# Umsetzungsplan

## Stand März 2026
Der ursprüngliche Fenster-MVP wurde in dieser Umgebung zu einem **Terminal-MVP** verdichtet, weil die verfügbare Toolchain ohne zusätzliche GUI-Bibliotheken auskommen soll. Die Kernidee bleibt gleich: Algorithmen erzeugen Schritte, Playback spielt sie ab, Rendering visualisiert sie.

## Bereits erledigt
1. Projektgerüst mit CMake und Bibliotheksstruktur
2. `Application` und `AppState` als zentrale Ablauf- und Zustandskomponenten
3. Datensatzmodell und Presets
4. `AlgorithmStep`-Struktur mit Snapshot-Ansatz
5. Bubble Sort als erste End-to-End-Implementierung
6. PlaybackController und Timeline
7. moderne Terminal-Darstellung mit Kartenlayout und ANSI-Farben
8. automatische Tests für Kernlogik

## Empfohlene nächste Reihenfolge
1. interaktive Eingaben an `UiManager` anbinden
2. weitere Sortieralgorithmen fertig implementieren
3. Theme-/Konfigurationsdateien wirklich laden und anwenden
4. optionales SFML-/ImGui-Frontend ergänzen
5. zweite Algorithmus-Kategorie wie Graphen hinzufügen

## Definition of Done für den nächsten Meilenstein
- mindestens drei Sortieralgorithmen sind lauffähig
- Presets und Geschwindigkeit sind zur Laufzeit änderbar
- ein grafisches Frontend oder eine echte interaktive Terminalsteuerung existiert
- Dokumentation und README sind synchron mit dem Code
