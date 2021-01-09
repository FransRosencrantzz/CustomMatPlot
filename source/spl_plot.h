#pragma once

#include "spl_graph_line.h"
#include "spl_grid.h"
#include "spl_label.h"
#include <juce_gui_basics/juce_gui_basics.h>

struct Plot : juce::Component {
public:
  Plot() = default;
  ~Plot() = default;

  void xLim(const float &min, const float &max);
  void yLim(const float &min, const float &max);

  virtual void updateYData(const std::vector<std::vector<float>> &y_data) = 0;
  virtual void updateXData(const std::vector<std::vector<float>> &x_data) = 0;

  void setXLabel(const std::string &x_label);
  void setYLabel(const std::string &y_label);
  void setTitle(const std::string &title);

  void makeGraphDashed(const std::vector<float> &dashed_lengths,
                       unsigned graph_index);
  void gridON(const bool grid_on);

  void resized() override;
  void paint(juce::Graphics &g) override;

protected:
  void setAutoXScale(const std::vector<std::vector<float>> &x_data);
  void setAutoYScale(const std::vector<std::vector<float>> &y_data);

  void updateYDataGraph();
  void updateXDataGraph();

  void updateYLim(const float &min, const float &max);
  void updateXLim(const float &min, const float &max);

  bool m_x_autoscale = true, m_y_autoscale = true;

  std::vector<std::unique_ptr<GraphLine>> m_graph_lines;
  std::unique_ptr<BaseGrid> m_grid;
  PlotLabel m_plot_label;

  juce::Rectangle<int> m_graph_area, m_plot_area;
  std::vector<std::vector<float>> m_y_data, m_x_data;

  float m_horizontal_margin, m_vertical_margin = 0.1f;
};

struct LinearPlot : Plot {
public:
  ~LinearPlot() = default;
  LinearPlot(const int x, const int y, const int width, const int height);
  LinearPlot();
  void updateYData(const std::vector<std::vector<float>> &y_data) override;
  void updateXData(const std::vector<std::vector<float>> &x_data) override;
};

struct SemiPlotX : Plot {
public:
  ~SemiPlotX() = default;
  SemiPlotX();
  void updateYData(const std::vector<std::vector<float>> &y_data) override;
  void updateXData(const std::vector<std::vector<float>> &x_data) override;
};
