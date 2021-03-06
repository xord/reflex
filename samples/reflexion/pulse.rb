# -*- coding: utf-8 -*-


%w[xot rays reflex]
  .map  {|s| File.expand_path "../../../../#{s}/lib", __FILE__}
  .each {|s| $:.unshift s if !$:.include?(s) && File.directory?(s)}

require 'reflexion/include'


frame = 0
fps   = 0


setup do
  set width: 600, height: 300
  painter.font = Font.new nil, 24
end

draw do
  frame += 1
  fps = event.fps.to_i if (frame % 5) == 0
  text "#{fps} FPS | FRAME: #{frame}", 10, 10
end

key do
  quit if chars == 'q' || code == 53
end

pointer do
  if down? || drag?
    window.add EllipseShape.new {
      set frame: [*(event.pos - 10).to_a, 20, 20], fill: :red
    }
  end
end
